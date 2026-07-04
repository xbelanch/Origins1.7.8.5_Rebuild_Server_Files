# Production deployment

No despleguis una build només perquè compila. Cal una declaració explícita d'estabilitat i validació.

1. Selecciona el PBO estable a `Export/` i registra nom, build ID, nota i manifest.
2. Executa `sha256sum Export/<build>.pbo` i compara sidecar/manifest.
3. Fes backup del PBO actiu de `<PRODUCTION_SERVER_PATH>` a `<BACKUP_PATH>` amb timestamp.
4. Atura o reinicia el servidor segons el procediment operatiu acordat; no substitueixis un PBO mentre és en ús si la plataforma no ho garanteix.
5. Copia només el PBO seleccionat a la ubicació del component corresponent.
6. Inicia/reinicia i revisa `<RPT_LOG_PATH>`: identitat de build, errors SQF, prefix/dependències i lifecycle afectat.
7. Executa el smoke test autoritzat.

Rollback: atura el servidor, conserva logs i artefacte fallit, restaura el backup verificat, reinicia, confirma la build anterior al RPT i documenta l'incident. Les rutes són placeholders perquè el repositori no defineix una topologia de producció canònica.
