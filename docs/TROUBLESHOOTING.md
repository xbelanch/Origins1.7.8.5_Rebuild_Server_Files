# Troubleshooting

| Símptoma | Lectura/acció segura |
|---|---|
| Preview ghost a trompicones | Build antiga o validació dins el loop de moviment. Compara amb la baseline movement-decoupled; no reintrodueixis validació pesada per frame. |
| Prefix PBO incorrecte | Inspecciona amb `tools/bin/unpbo -v -l`; reconstrueix amb l'script del component, no renomis simplement el PBO. |
| SHA mismatch | No despleguis. Recalcula, compara sidecar/manifest i confirma que no s'ha sobreescrit l'artefacte. |
| Stage Two funciona només al client | És el risc pendent; no el consideris segur fins a `house-l1-stage2-server-validation-v1`. |
| Foundation wet/set inesperada | El canvi és implícit després de hive reload. Verifica classe persistent/runtime abans d'afegir transicions. |
| Errors DB | Atura't: production DB ha de quedar untouched. Reprodueix en shadow DB i prepara backup/rollback. |
| Build no reflectida al joc | Comprova PBO desplegat, hash, prefix i línia d'identitat al RPT; evita deduir-ho només pel nom. |
