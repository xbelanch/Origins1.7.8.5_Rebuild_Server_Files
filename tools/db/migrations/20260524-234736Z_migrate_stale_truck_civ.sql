-- A2EDC migration: stale Origins truck variants no longer exist in the reconstructed 1.7.9 client config.
-- Scope: object_data only. Do not touch ori_vil_truck_civ_base.
-- Rollback: tools/db/migrations/20260524-234736Z_migrate_stale_truck_civ_rollback.sql

CREATE TABLE IF NOT EXISTS a2edc_backup_object_data_truck_civ_20260524_234736 AS
SELECT *
FROM object_data
WHERE Classname IN ('ori_vil_originsmod_truck_civ1', 'ori_vil_originsmod_truck_civ2');

START TRANSACTION;

UPDATE object_data
SET Classname = 'ori_vil_originsmod_truck_civ'
WHERE Classname IN ('ori_vil_originsmod_truck_civ1', 'ori_vil_originsmod_truck_civ2');

COMMIT;

SELECT Classname, COUNT(*) AS count
FROM object_data
WHERE Classname IN (
  'ori_vil_originsmod_truck_civ1',
  'ori_vil_originsmod_truck_civ2',
  'ori_vil_originsmod_truck_civ',
  'ori_vil_truck_civ_base'
)
GROUP BY Classname
ORDER BY Classname;
