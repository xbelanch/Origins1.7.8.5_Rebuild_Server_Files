# Origins 1.7.8.5 rebuild server files

Workspace independent de preservació, reconstrucció i operació d'un servidor comunitari DayZ Origins 1.7.8.5, amb material experimental de compatibilitat 1.7.9. No és una release oficial neta: combina runtime, fonts reconstruïdes, referències, eines i artefactes històrics.

## Estat estable

La baseline funcional congelada és `dayz_code build_id=20260607-154328`, nota `house-l1-preview-movement-decoupled-v1`. L'artefacte desplegable és `Export/dayz_code_20260607-154328_house-l1-preview-movement-decoupled-v1.pbo`, SHA256 `9651298e7a9397b66f766a1abd6ac944c2e5f6619997f367f82ce0168efbd27e`, prefix `z\addons\dayz_code`.

Ha estat validada in-game segons el registre del projecte. Aquesta tasca documental no l'ha tornat a executar. El milestone següent és `house-l1-stage2-server-validation-v1`; encara no està implementat.

## Com començar

Consulta [l'índex de documentació](docs/INDEX.md). Hi trobaràs rutes de lectura per implementar features, reconstruir PBOs, validar canvis i desplegar a producció.

Abans de modificar res, llegeix [l'estructura del projecte](docs/PROJECT_STRUCTURE.md), [la baseline actual](docs/CURRENT_BASELINE.md) i [el workflow de features](docs/FEATURE_WORKFLOW.md). No modifiquis `Repositories/`, fonts de referència o artefactes estables; no executis SQL ni substitueixis PBOs de producció sense backup i autorització explícita.
