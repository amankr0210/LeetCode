# Write your MySQL query statement below
SELECT today.id
FROM Weather AS today
WHERE EXISTS
# 1 is fisrt row of table that is act as yeserday
 (
    SELECT 1
    FROM Weather AS yesterday
    WHERE yesterday.temperature < today.temperature
      AND DATEDIFF(today.recordDate, yesterday.recordDate) = 1
);