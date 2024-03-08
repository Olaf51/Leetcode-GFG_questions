# Write your MySQL query statement below
select e1.name as Employee
From Employee as e1
LEFT Join Employee as e2
ON e1.managerId = e2.id
Where e1.salary > e2.salary;