# Project structure

| Ruta | Rol | Política |
|---|---|---|
| `@dayz_1.origins.tavi/` | Runtime servidor: addon `dayz_server` i HiveExt | Crític; no moure. Canviar només dins un milestone explícit. |
| `dayz_1.origins.tavi/` | Configuració servidor i BattlEye | Runtime/operacions; pot contenir secrets locals. |
| `MPMissions/` | Font i PBO actiu de la missió | Runtime client/servidor; preservar paths. |
| `Sandbox/origins_179_rebuild/dayz_code_merged_src/` | Font de rebuild activa de `dayz_code` | Workspace reconstruït, no font oficial pura. |
| `Export/` | PBOs, hashes, manifests i auditories lliurables | Artefactes immutables; no sobreescriure ni moure. |
| `scripts/` | Pipelines Python de rebuild | Eines actives; poden escriure metadata de build a les fonts. |
| `tools/` | Binaris PBO, auditories, DB, claus i backups | Eines sensibles; no executar DB/keys per rutina. |
| `SQLfile/` | Esquema i updates històrics | No modificar ni executar a producció sense pla. |
| `Repositories/` | Repositoris externs de referència | Read-only; no confondre amb font activa. |
| `Sandbox/` | Material de referència i reconstrucció | Només el subtree identificat com a font activa es modifica deliberadament. |
| `installP/` | Material comunitari d'instal·lació | Històric/operatiu; procedència mixta. |
| `.audit/` | Inventaris i verificacions locals | Evidència generada; no runtime. |
| `docs/` | Documentació vigent i arxiu | Entrada via `docs/INDEX.md`. |

DLLs, keys, configuracions, missions, PBOs actius i scripts `.cmd` romanen al root o a les ubicacions que espera el runtime. La reorganització documental no justifica moure'ls.
