# Write your MySQL query statement below
-- select e.name
-- from Employee e
-- join Employee e1
-- on e.id = e1.managerId
-- group by e1.managerId
-- having count(*) >=5;
select name from Employee where id in 
(
    select managerId from Employee
    group by managerId
    having count(*)>=5
);
