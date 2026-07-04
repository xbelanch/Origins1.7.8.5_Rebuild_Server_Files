# Build and export

Els scripts generen un PBO a `Export/`, el seu `.pbo.sha256`, un `.manifest.json` i una verificació desempaquetada sota `.audit/verify/`. També injecten metadata de build a la font: revisa el diff després d'executar-los.

```bash
timeout 120s python3 scripts/rebuild_dayz_code_pbo.py --build-note <note>
timeout 120s python3 scripts/rebuild_dayz_server_pbo.py --build-note <note>
timeout 120s python3 scripts/rebuild_mpmission_pbo.py --build-note <note>
```

Opcions comunes: `--build-id`, `--build-note`, `--output-name`. Consulta `python3 scripts/<script>.py --help`. No executis tots tres si només canvia un component.

| Script | Font | Prefix esperat |
|---|---|---|
| `rebuild_dayz_code_pbo.py` | `Sandbox/origins_179_rebuild/dayz_code_merged_src` | `z\addons\dayz_code` |
| `rebuild_dayz_server_pbo.py` | `@dayz_1.origins.tavi/addons/dayz_server` | `z\addons\dayz_server` |
| `rebuild_mpmission_pbo.py` | `MPMissions/dayz_1.origins.tavi` | sense prefix, per compatibilitat amb la missió activa |

Convenció: `<component>_<YYYYMMDD-HHMMSS>_<note>.pbo`. Mantén la nota curta, única i segura per a noms de fitxer.

Verifica el hash amb `sha256sum Export/<build>.pbo` i compara'l amb el `.pbo.sha256` i el camp `sha256` del manifest. Verifica el prefix amb `tools/bin/unpbo -v -l Export/<build>.pbo`; ha de coincidir amb la taula. Un hash diferent no és equivalent encara que el nom coincideixi.
