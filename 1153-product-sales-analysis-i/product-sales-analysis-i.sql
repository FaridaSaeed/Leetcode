# Write your MySQL query statement below
select product_name , year, price 
from Product p , Sales s
where p.product_id = s.product_id