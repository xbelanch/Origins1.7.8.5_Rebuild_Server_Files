-- A2EDC rollback for 20260524-234736Z_migrate_stale_truck_civ.sql.
-- Restores only rows captured in a2edc_backup_object_data_truck_civ_20260524_234736.

START TRANSACTION;

UPDATE object_data od
JOIN a2edc_backup_object_data_truck_civ_20260524_234736 backup
  ON od.ObjectID = backup.ObjectID
SET od.Classname = backup.Classname
WHERE backup.Classname IN ('ori_vil_originsmod_truck_civ1', 'ori_vil_originsmod_truck_civ2');

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
