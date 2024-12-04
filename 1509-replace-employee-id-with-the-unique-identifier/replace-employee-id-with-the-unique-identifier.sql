# Write your MySQL query statement below
select unique_id , name 
from EmployeeUNI as un right join Employees as e
on un.id = e.id