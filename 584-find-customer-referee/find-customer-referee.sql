# Write your MySQL query statement below
select c.name as name
from Customer as c
where referee_id <> 2
or referee_id is NULL;