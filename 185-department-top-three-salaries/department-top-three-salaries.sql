# Write your MySQL query statement below
with cte as (select 
dense_rank() over(partition by e.departmentId order by e.salary desc) as ds,
d.name Department, e.name Employee, e.salary Salary from department d
 join Employee e
on d.id = e.departmentId
)
select 
Department, Employee, Salary 
from cte
where ds <=3
order by Employee
