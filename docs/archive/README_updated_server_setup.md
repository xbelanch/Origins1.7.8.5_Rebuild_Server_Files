> Historical document. Kept for reference. Current entrypoint: [../INDEX.md](../INDEX.md)

# DayZ Origins 1.7.8.5 / 1.7.9 Reconstruction Server Setup

Aquest repositori conté una base comunitària funcional per muntar un servidor **DayZ Origins 1.7.8.5** i, alhora, el treball de reconstrucció i compatibilitat que s’ha anat fent per provar una línia **1.7.9** amb els materials disponibles.

No és una release oficial neta de servidor. És un entorn de preservació, arqueologia tècnica i reconstrucció que combina:

- fitxers comunitaris de servidor;
- una missió Taviana/Origins funcional;
- materials `installP`;
- clients oficials de referència 1.7.8.5 i 1.7.9 dins `Sandbox`;
- eines pròpies per manipular PBOs;
- patches locals per fer funcionar la combinació actual de client, servidor, missió i base de dades.

L’objectiu és tenir un servidor Origins executable i documentat, preservant sempre les fonts originals i separant clarament els artefactes generats.

## Estat actual del projecte

L’estructura actual del repositori és aproximadament:

```text
.
├── @dayz_1.origins.tavi
│   ├── addons
│   │   ├── dayz_server
│   │   └── dayz_server.pbo
│   └── HiveExt.dll
├── dayz_1.origins.tavi
│   ├── basic.cfg
│   ├── BattlEye
│   ├── config.cfg
│   └── HiveExt.ini
├── installP
│   └── addons
│       ├── dayz_code.pbo
│       ├── dayz_equip.pbo
│       └── origins_pack
├── MPMissions
│   ├── dayz_1.origins.tavi
│   └── dayz_1.origins.tavi.pbo
├── SQLfile
│   ├── dayz_origins.sql
│   ├── update.sql
│   ├── update3.sql
│   └── update4.sql
├── tools
│   ├── bin
│   ├── db
│   ├── backups
│   └── keys
├── Sandbox
│   ├── @DayzOrigins1785
│   ├── @DayzOrigins179
│   └── origins_179_rebuild
├── Export
├── scripts
│   └── rebuild_dayz_server_pbo.py
├── originsserver.cmd
├── originsclient.cmd
├── install.cmd
├── update.cmd
└── README.md
```

La separació conceptual és important:

| Directori | Funció |
|||
| `@dayz_1.origins.tavi/` | Mod/server package carregat pel servidor. Conté `dayz_server.pbo`, la versió desempaquetada i `HiveExt.dll`. |
| `dayz_1.origins.tavi/` | Configuració del servidor: `config.cfg`, `basic.cfg`, `HiveExt.ini` i filtres BattlEye. |
| `MPMissions/` | Missió Taviana/Origins, tant desempaquetada com empaquetada. |
| `installP/` | Material comunitari d’instal·lació/reconstrucció. No s’ha de tractar com a font oficial neta. |
| `SQLfile/` | Esquemes i actualitzacions SQL per crear o actualitzar la base de dades Origins. |
| `tools/bin/` | Toolchain actual per manipular PBOs, rapificar configs i validar builds. |
| `tools/db/` | Scripts auxiliars per consultar, auditar i fer backups de la base de dades. |
| `Sandbox/` | Fonts i referències originals. No modificar directament. |
| `Export/` | Directori obligatori per deixar-hi PBOs nous generats i lliurables. |
| `scripts/` | Scripts locals de rebuild, especialment per reconstruir `dayz_server.pbo`. |

## Avís important sobre procedència

El `installP/addons/dayz_code.pbo` inclòs en aquesta base comunitària **no s’ha de considerar un artefacte oficial net**.

L’auditoria actual indica que:

- el client oficial 1.7.8.5 té un `dayz_code.pbo` relativament “slim”;
- el client oficial 1.7.9 també té un `dayz_code.pbo` “slim”;
- el `dayz_code.pbo` gran que apareix dins `installP/addons` conté molts scripts extra sota:
  - `actions/`
  - `compile/`
  - `medical/`
  - `init/`
  - `system/`
  - recursos UI i definicions antigues.

Aquest `dayz_code.pbo` d’`installP` sembla comunitari, derivat de servidor o reconstruït, no un client oficial pur. Conté indicadors com `un-official server` i `DEBUG: pirated server`, i el seu `hiveVersion` no coincideix amb el client oficial 1.7.8.5.

Per això, qualsevol merge actual de `dayz_code` per a proves 1.7.9 s’ha de descriure com una **capa de compatibilitat**, no com una reconstrucció oficial fidel.

## Requisits

### Joc base

Cal tenir instal·lats:

- **Arma 2**
- **Arma 2: Operation Arrowhead**

La instal·lació ha de funcionar com a **Combined Operations**, és a dir, Operation Arrowhead ha de veure també el contingut d’Arma 2.

La instrucció comunitària original era copiar tots els fitxers i carpetes d’Arma 2 dins la carpeta d’Operation Arrowhead. Això pot funcionar, però també es pot fer amb junctions/symlinks o una estructura equivalent, sempre que el servidor OA pugui carregar `ca`, `addons`, `Expansion`, etc.

### Base de dades

El servidor Origins necessita MySQL. En aquest projecte s’ha validat l’ús de **MySQL 5.7** en Docker, però també pot funcionar amb una instal·lació Windows clàssica si `HiveExt.ini` queda ben configurat.

La base de dades esperada és:

```sql
CREATE DATABASE dayz_origins
  CHARACTER SET utf8
  COLLATE utf8_general_ci;
```

### Eines PBO

El README comunitari antic demanava **PBO Manager**. Encara s’inclou `pbo_manager_v14.7z`, però el flux actual recomanat és usar les eines locals de:

```text
tools/bin/
```

Actualment hi ha:

```text
tools/bin/
├── bisign
├── makepbo
├── pbocmp
├── rapify
├── unpbo
└── unrap
```

Aquestes eines permeten:

- desempaquetar PBOs;
- empaquetar PBOs;
- conservar prefixos;
- comparar PBOs;
- rapificar `config.cpp` a `config.bin`;
- desrapificar configs;
- signar si cal;
- preparar builds reproductibles.

## Instal·lació inicial del servidor 1.7.8.5 comunitari

### 1. Preparar la carpeta d’Arma 2 OA

Instal·la Arma 2 i Operation Arrowhead des de Steam.

La carpeta final de servidor ha de tenir accés al contingut d’Arma 2 i OA. Una estructura típica seria:

```text
arma2oa/
├── arma2oaserver.exe
├── addons/
├── ca/
├── Expansion/
├── @DayZOriginsP/
├── @dayz_1.origins.tavi/
├── dayz_1.origins.tavi/
├── MPMissions/
└── Keys/
```

El nom exacte de la carpeta del client Origins pot variar segons el paquet instal·lat.

### 2. Copiar els fitxers d’aquest repositori

Copia o extreu els fitxers d’aquest repositori dins la carpeta d’Operation Arrowhead / servidor.

Els elements importants són:

```text
@dayz_1.origins.tavi/
dayz_1.origins.tavi/
MPMissions/
installP/
SQLfile/
Keys/
DatabaseMySql.dll
DatabasePostgre.dll
originsserver.cmd
originsclient.cmd
install.cmd
update.cmd
tbb.dll
tbbmalloc.dll
```

En una instal·lació Windows clàssica, `originsserver.cmd` és el punt d’arrencada principal.

### 3. Construir `origins_pack.pbo`

El README comunitari original indicava que calia empaquetar primer:

```text
installP/addons/origins_pack
```

Abans es feia amb PBO Manager:

1. instal·lar PBO Manager;
2. clic dret sobre `installP/addons/origins_pack`;
3. `Pack into PBO`.

Amb el flux actual, és preferible usar `tools/bin/makepbo` i deixar el resultat a `Export/`.

Exemple conceptual:

```bash
tools/bin/makepbo installP/addons/origins_pack Export/origins_pack.pbo
```

Cal verificar el prefix real esperat abans de desplegar-lo. No assumeixis que un PBO generat manualment és correcte sense validar-lo.

Després de generar-lo, copia `origins_pack.pbo` al lloc que esperi el client/mod Origins segons la instal·lació activa.

### 4. Executar `install.cmd`

El flux comunitari original utilitza:

```text
install.cmd
```

per crear o preparar:

```text
@DayZOriginsP/
```

Executa’l només després d’haver verificat que:

- `installP/` existeix;
- `installP/addons/dayz_code.pbo` existeix;
- `installP/addons/dayz_equip.pbo` existeix;
- `origins_pack.pbo` ha estat creat si el script l’espera;
- la ruta d’Operation Arrowhead és correcta.

### 5. Importar la base de dades

Els fitxers SQL disponibles són:

```text
SQLfile/
├── dayz_origins.sql
├── update.sql
├── update3.sql
└── update4.sql
```

Ordre recomanat per a una instal·lació nova:

```bash
mysql -u <user> -p -e "CREATE DATABASE dayz_origins CHARACTER SET utf8 COLLATE utf8_general_ci;"
mysql -u <user> -p dayz_origins < SQLfile/dayz_origins.sql
mysql -u <user> -p dayz_origins < SQLfile/update.sql
mysql -u <user> -p dayz_origins < SQLfile/update3.sql
mysql -u <user> -p dayz_origins < SQLfile/update4.sql
```

Si utilitzes Docker/MySQL remot, adapta host i port:

```bash
mysql --protocol=TCP -h <db_host> -P 3306 -u <user> -p dayz_origins < SQLfile/dayz_origins.sql
```

Després verifica:

```sql
SHOW DATABASES;
USE dayz_origins;
SHOW TABLES;
```

### 6. Revisar casing de taules i vistes

En restauracions Origins/DayZ és habitual trobar diferències entre noms de taules en minúscula i noms esperats pel servidor.

El servidor pot esperar noms com:

```text
Object_DATA
Object_CLASSES
Object_SPAWNS
Player_DATA
Character_DATA
```

Si la base de dades conté noms en minúscula, caldrà crear vistes compatibles o ajustar l’esquema. No ho facis a cegues: comprova primer què espera `HiveExt` i què existeix realment.

Consulta útil:

```sql
SHOW FULL TABLES;
```

### 7. Configurar `HiveExt.ini`

El fitxer actual és:

```text
dayz_1.origins.tavi/HiveExt.ini
```

Configura:

- host;
- port;
- usuari;
- contrasenya;
- base de dades;
- driver MySQL;
- qualsevol ruta específica si fas servir Windows.

Si la DB és Dockeritzada, assegura’t que la VM/servidor Windows pot arribar al host Docker per TCP.

### 8. Configurar `config.cfg` i `basic.cfg`

Els fitxers són:

```text
dayz_1.origins.tavi/config.cfg
dayz_1.origins.tavi/basic.cfg
```

Configura com a mínim:

- nom del servidor;
- password si cal;
- password admin;
- missió activa;
- port;
- nombre màxim de jugadors;
- paràmetres de xarxa;
- logs;
- verify signatures segons el teu estat de claus.

### 9. Configurar BattlEye

Els filtres BattlEye són a:

```text
dayz_1.origins.tavi/BattlEye/
```

Actualment hi ha filtres per:

```text
addbackpackcargo.txt
addmagazinecargo.txt
addweaponcargo.txt
attachto.txt
createvehicle.txt
deleteVehicle.txt
mpeventhandler.txt
publicvariable.txt
publicvariableval.txt
publicvariablevar.txt
remotecontrol.txt
remoteexec.txt
scripts.txt
selectplayer.txt
setdamage.txt
setpos.txt
setvariable.txt
setvariableval.txt
teamswitch.txt
```

També hi ha:

```text
BEServer.cfg
BEServer.dll
bans.txt
```

Els filtres són sensibles. No els relaxis globalment per solucionar un kick concret. Primer cal mirar el log corresponent.

### 10. Configurar admintools

La missió desempaquetada és:

```text
MPMissions/dayz_1.origins.tavi/
```

Els admin tools són a:

```text
MPMissions/dayz_1.origins.tavi/admintools/
```

Cal reinserir el teu PlayerID/UID als fitxers corresponents. No conservis IDs antics del paquet comunitari.

També cal tenir present que algunes accions admin poden activar BattlEye si creen objectes, crates o manipulen càrrega des del client.

### 11. Arrencar el servidor

El launcher comunitari principal és:

```text
originsserver.cmd
```

Una línia d’arrencada funcional pot tenir aquesta forma conceptual:

```text
arma2oaserver.exe
-port=2422
-bepath=<ruta>\dayz_1.origins.tavi\BattlEye
-mod=Expansion\beta;Expansion\beta\expansion;ca;@dayzoriginsP;@dayz_1.origins.tavi
-config=<ruta>\dayz_1.origins.tavi\config.cfg
-cfg=<ruta>\dayz_1.origins.tavi\basic.cfg
-profiles=<ruta>\dayz_1.origins.tavi
-name=origins-mod-server
```

Mantén l’ordre de mods validat. En Arma 2, l’ordre de càrrega pot canviar completament el resultat.

## Flux actual de rebuild de PBOs

### Regla principal

No modifiquis fonts originals dins `Sandbox/`.

No deixis PBOs finals només en directoris temporals.

Qualsevol PBO nou generat ha d’anar a:

```text
Export/
```

amb:

- nom identificable;
- build id;
- SHA256;
- manifest;
- prefix verificat;
- notes de font i validació.

### `dayz_server.pbo`

El servidor actual té:

```text
@dayz_1.origins.tavi/addons/dayz_server/
@dayz_1.origins.tavi/addons/dayz_server.pbo
```

Hi ha un script local per reconstruir-lo:

```text
scripts/rebuild_dayz_server_pbo.py
```

La política recomanada és:

1. editar la versió desempaquetada només si el canvi està justificat;
2. reconstruir amb prefix correcte:

```text
z\addons\dayz_server
```

3. exportar el PBO nou a `Export/`;
4. copiar-lo al directori de deploy només després de validar;
5. conservar SHA256 i build id.

### `dayz_code.pbo`

Per a la línia 1.7.9 s’ha creat un merge dins:

```text
Sandbox/origins_179_rebuild/
├── dayz_code_merged_deploy
└── dayz_code_merged_src
```

Aquest merge és una capa de compatibilitat:

```text
1.7.9 client/config/assets
+
installP legacy script API surface
```

No s’ha de reduir encara. L’auditoria actual classifica els fitxers restaurats així:

```text
keep: 148
investigate: 23
candidate_remove_later: 37
```

La majoria dels fitxers candidats a eliminar són recursos GUI/stat antics. Els scripts d’accions, compilació, medical, monitor, public event handlers i vehicle/player sync són d’alt risc.

## Canvis ja assolits respecte el README comunitari original

### 1. Toolchain pròpia

Abans:

```text
PBO Manager
```

Ara:

```text
tools/bin/unpbo
tools/bin/makepbo
tools/bin/rapify
tools/bin/unrap
tools/bin/pbocmp
tools/bin/bisign
```

Això permet builds més reproductibles i auditories de prefix/config.

### 2. Separació entre fonts i artefactes

Abans el README original assumia copiar i sobreescriure carpetes directament.

Ara:

```text
Sandbox/ = fonts/referències, no tocar
Export/  = PBOs generats i lliurables
```

### 3. Base de dades auditable

Ara hi ha scripts específics:

```text
tools/db/
├── a2edc-db.env
├── a2edc-db.env.example
├── a2edc-db-shadow.env
├── a2edc-db-shadow.env.example
├── backup-dayz-origins.sh
├── db-query.sh
├── inspect-gender-state.sh
└── inspect-gender-state-shadow.sh
```

Això permet:

- consultar producció;
- consultar shadow DB;
- fer backups;
- inspeccionar estat de gender/player;
- provar migracions sense tocar producció.

### 4. Patches funcionals aplicats a `dayz_server`

En el treball recent de reconstrucció 1.7.9 s’ha aplicat un patch mínim a `dayz_server.pbo`.

Canvis principals ja assolits:

- correcció del flux gender/setup;
- `server_playLogni.sqf` desa:
  - `A2EDC_needsGenderSelect`
  - `A2EDC_loginModel`
- `serverDO_plSp2.sqf` respecta la decisió de login i evita `selectSex=true` fals per `stats-too-short`;
- `server_monitor.sqf` inicialitza:
  - `dayz_serverObjectMonitor`
  - `serverObjectMonitor`
  - `dayz_serverMonitor`
  - `serverMonitor`
  - `sm_done`
- `allowConnection=true` i `sm_done=true` queden establerts al final del monitor;
- WAI/DZMS tenen shim explícit:
  - `A2EDC_PVDZE_serverObjectMonitorShim=true`
- DZMS ja no hauria de detectar falsament Epoch;
- WAI ja no usa `ori_vil_originsmod_truck_civ1/2` als pools de camions.

Build validat:

```text
dayz_server.pbo
prefix: z\addons\dayz_server
build_id: 20260523-232941
sha256: 727a22f2004d54b2f6751e16596d44973fa9dbcfb3152449387b3107b21a2abf
```

## Problemes coneguts actuals

### 1. Vehicles stale a la base de dades

Encara hi ha objectes antics:

```text
ori_vil_originsmod_truck_civ1
ori_vil_originsmod_truck_civ2
```

A 1.7.9 aquests classnames són stale o no tenen definició real de `CfgVehicles`.

Probable migració:

```text
ori_vil_originsmod_truck_civ1 -> ori_vil_originsmod_truck_civ
ori_vil_originsmod_truck_civ2 -> ori_vil_originsmod_truck_civ
```

Consulta prèvia:

```sql
SELECT Classname, COUNT(*) AS rows_count
FROM Object_DATA
WHERE Classname IN (
  'ori_vil_originsmod_truck_civ1',
  'ori_vil_originsmod_truck_civ2',
  'ori_vil_originsmod_truck_civ',
  'ori_vil_truck_civ_base'
)
GROUP BY Classname;
```

No migrar sense backup.

### 2. Admin crate provoca kick BattlEye

En proves recents, crear un crate com a admin provoca expulsió.

El RPT mostra:

```text
BE protection kicked in
msgType=68
msgType=40
```

Cal mirar logs BattlEye, especialment:

```text
createvehicle.log
scripts.log
publicvariable.log
remoteexec.log
setvariable.log
setvariableval.log
addweaponcargo.log
addmagazinecargo.log
addbackpackcargo.log
attachto.log
```

No relaxar filtres globalment. La solució preferible és moure la creació de crates admin a un handler server-side validat.

### 3. Anomalia de persistència amb `ORI_gunship_helicopter`

S’ha observat que l’objecte persistent:

```text
ORI_gunship_helicopter
```

amb un `ObjectID` concret pot acabar passant per rutines on `_object` sembla ser el player, no el vehicle.

Això pot afectar:

- `dayUpdateVehlcle`;
- `server_updateObject`;
- `player sync`;
- force-save;
- disconnect/combat log;
- persistència de vehicles.

Cal auditar abans de tocar configs de vehicles.

### 4. Warnings de vehicles

Encara hi ha warnings de config relacionats amb:

- `HitPoints` inexistents;
- `Damage/tex[]` no parells;
- animation sources desconeguts.

Classes afectades observades:

```text
ori_vil_truck_civ_base
ori_vil_originsmod_truck_civ
ori_p85_originsmod_CUCV
ori_survivorBus
```

No són bloquejants ara mateix. Prioritzar gameplay, admin tools i persistència.

## Ajust opcional: teleport / vehicle eject fix

El README comunitari original suggeria modificar:

```text
MPMissions/dayz_1.origins.tavi/Debug/player_spawn_2.sqf
```

per augmentar llindars anti-teleport.

Originalment:

```sqf
if (player == vehicle player) then {
    if (_mylastPos distance _lastPos > 200) then {
        if (alive player) then {
            player setPosATL _mylastPos;
        };
    };
} else {
    if (_mylastPos distance _lastPos > 800) then {
        if (alive player) then {
            player setPosATL _mylastPos;
        };
    };
};
```

Workaround comunitari:

```text
200 -> 20000
800 -> 80000
```

Això evita falsos positius amb admin tools, boost de vehicles o avions a Taviana.

Recomanació actual:

- acceptable temporalment en entorn de proves;
- no recomanat com a solució definitiva;
- millor distingir moviment legítim en vehicle/aircraft/admin d’un teleport real.

## Smoke tests recomanats

Abans de reduir `dayz_code`, tocar filtres BE agressivament o modificar persistència, cal provar:

1. Login amb personatge existent.
2. Login amb personatge nou.
3. Selecció de sexe.
4. Spawn inicial.
5. Mort i respawn.
6. Bandage.
7. Morphine.
8. Painkillers.
9. Antibiotics.
10. Blood/transfusion si està disponible.
11. Entrar i sortir de vehicle.
12. Reparar vehicle.
13. Repostar vehicle.
14. Force-save vehicle.
15. Reiniciar servidor i validar persistència.
16. Dany i destrucció de vehicle.
17. Spawn de loot.
18. Spawn de zombies.
19. Construcció/remoció/lock/unlock d’objectes o cases.
20. Admin teleport.
21. Admin vehicle boost.
22. Admin crate.
23. Admin spawn vehicle.
24. Admin delete object.
25. WAI/DZMS mission spawn.
26. WAI/DZMS AI combat.
27. WAI/DZMS reward crate.
28. Cleanup de missions.
29. BattleEye createVehicle.
30. BattleEye publicVariable.
31. BattleEye script restrictions.
32. BattleEye cargo restrictions.
33. UI/status icons.
34. Debug monitor.
35. Loading screens.
36. Dialogs/actions.

## Flux recomanat de treball

### Per canvis de codi

1. Identificar error al RPT/logs.
2. Localitzar fitxer exacte.
3. Fer patch mínim.
4. Reconstruir PBO amb prefix correcte.
5. Copiar build a `Export/`.
6. Generar SHA256.
7. Desplegar a servidor.
8. Arrencar i provar.
9. Guardar RPT/logs.
10. Documentar resultat.

### Per canvis de DB

1. Fer backup.
2. Provar en shadow DB si és possible.
3. Executar `SELECT` preflight.
4. Aplicar migració mínima.
5. Executar `SELECT` postflight.
6. Arrencar servidor.
7. Revisar RPT.
8. Preparar rollback.

### Per canvis BattlEye

1. Reproduir kick.
2. Recollir log BattlEye exacte.
3. Identificar filtre i línia.
4. Evitar excepcions massa àmplies.
5. Preferir correcció server-side si l’acció és admin.
6. Provar de nou.
7. Documentar abans/després.

## Crèdits

Els fitxers comunitaris originals acrediten MDark pel treball de fer disponible aquesta base de servidor.

Aquest repositori afegeix treball de preservació, auditoria, reconstrucció, compatibilitat, tooling PBO i documentació.

## Nota de preservació

DayZ Origins no va deixar disponibles de manera completa i neta tots els materials server-side per a totes les versions. Per això, una reconstrucció funcional pot requerir:

- comparar clients oficials;
- conservar missions comunitàries;
- reconstruir PBOs;
- mantenir compat layers;
- documentar desviacions;
- validar amb RPT, HiveExt i logs BattlEye.

La regla principal del projecte és:

```text
Preservar originals.
Treballar en còpies.
Exportar artefactes.
Documentar cada canvi.
```
