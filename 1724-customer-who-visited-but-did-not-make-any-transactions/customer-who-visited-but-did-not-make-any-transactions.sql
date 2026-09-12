# Write your MySQL query statement below

SELECT customer_id, COUNT(*) as count_no_trans
FROM 
visits as v
LEFT JOIN 
transactions as t
ON 
v.visit_id = t.visit_id
WHERE 
t.transaction_id is NULL
GROUP BY customer_id
