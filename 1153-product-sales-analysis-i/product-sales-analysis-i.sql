# Write your MySQL query statement below

SELECT p.product_name, s.year, s.price
FROM
sales as s
LEFT JOIN
product as p
ON
s.product_id = p.product_id
