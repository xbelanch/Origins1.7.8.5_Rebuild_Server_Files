# Operations

El client carrega `dayz_code` i la MPMission; el dedicat carrega `dayz_server`, configuració, HiveExt i la missió. La confiança no és simètrica: el client pot presentar preview/UI, però el servidor ha d'autoritzar canvis persistents.

- `SQLfile/`: esquema/updates; preservar ordre i fer backup. No executar a production durant desenvolupament ordinari.
- `tools/db/`: consultes, backups i shadow DB. Els `.env` locals poden contenir secrets; no publicar-los.
- `Keys/` i `tools/keys/`: material de signatura/confiança. No regenerar, copiar o exposar claus privades casualment.
- `dayz_1.origins.tavi/BattlEye/`: filtres runtime. Canvis requereixen evidència de kick/log i validació específica.
- `MPMissions/`: contracte compartit client/servidor; paths i noms són sensibles.
- DLLs, `.cmd`, config i PBOs actius: no moure; formen part del layout operatiu heretat.

Generalment és segur editar documentació i crear artefactes nous a `Export/`. Codi runtime, DB, keys, filtres i referències requereixen milestone, backup i revisió específica.
