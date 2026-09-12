# Write your MySQL query statement below
SELECT eu.unique_id, e.name
FROM
employees as e
LEFT JOIN 
employeeUNI as eu
ON
e.id = eu.id