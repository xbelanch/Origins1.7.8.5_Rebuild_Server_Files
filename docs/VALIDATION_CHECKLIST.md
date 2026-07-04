# Validation checklist

## Abans del build

- [ ] Milestone i component afectat definits.
- [ ] `git status --short` capturat; canvis locals aliens preservats.
- [ ] Diff limitat als fitxers autoritzats; DB production untouched.
- [ ] Ownership client/server explícit i servidor autoritatiu per decisions persistents.
- [ ] No s'han tocat BattleEye, WAI, DZMS, launcher, onBack, Gear UI ni altres sistemes aliens.

## Després del build

- [ ] Existeixen `.pbo`, `.pbo.sha256` i `.manifest.json`.
- [ ] `sha256sum` coincideix amb sidecar i manifest.
- [ ] Prefix correcte (`dayz_code`/`dayz_server`) o absent per MPMission.
- [ ] Manifest identifica font, build ID, nota i estat git.
- [ ] Verificació post-pack completada i fitxers esperats presents.
- [ ] Diff revisat, inclosa metadata que el build hagi actualitzat.
- [ ] Logs esperats de build documentats; cap error silenciat.

## Abans de producció

- [ ] Build seleccionada declarada estable i validada en entorn segur.
- [ ] Hash recalculat just abans de copiar.
- [ ] Backup del PBO actiu preparat i rollback assajat/documentat.
- [ ] Rutes i finestra de restart confirmades.
- [ ] Pla de revisió RPT i criteri de rollback definits.
