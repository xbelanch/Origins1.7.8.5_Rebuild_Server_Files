# Feature workflow

1. Defineix un milestone petit, una hipòtesi i criteris d'acceptació/reversió.
2. Inspecciona read-only les crides, variables, classes i persistència implicades.
3. Identifica ownership: UI/preview al client; decisions, consum i persistència sensibles al servidor.
4. Fes el patch mínim. No aprofitis per reformatejar o tocar sistemes aliens.
5. Revisa el diff i construeix només el component afectat amb una nota única.
6. Valida amb [VALIDATION_CHECKLIST.md](VALIDATION_CHECKLIST.md), primer estàticament i després in-game en un entorn segur quan estigui autoritzat.
7. Registra build ID, hash, prefix, resultat i limitacions.
8. Reverteix si trenca la baseline, canvia ownership sense disseny, toca DB production o no es pot explicar el diff.

## Com demanar una tasca a Codex

Inclou objectiu, baseline, fitxers permesos/prohibits, criteris d'acceptació, proves autoritzades i format de lliurament. Demana explícitament que preservi canvis locals i que no faci commit si és el cas.

```text
Milestone: <nom-curt-v1>
Objectiu: <resultat observable>
Baseline: <build ID/PBO/SHA>
Pot tocar: <paths>
No pot tocar: <paths/sistemes>
Validació: <checks estàtics i/o in-game autoritzats>
Lliurament: diff, PBO+SHA+manifest, riscos; sense commit.
```
