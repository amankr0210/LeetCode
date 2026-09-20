# Write your MySQL query statement be
Select class
FROM Courses
GROUP BY class
HAVING COUNT(*) >= 5;
