# Write your MySQL query statement below
select MAX(salary) AS "SecondHighestSalary"  from employee
where salary < (select max(salary) from Employee)