# Write your MySQL query statement below
-- select
--  a.id
--  from 
--  Weather b join Weather a
-- where
--      datediff(a.recordDate,b.recordDate) = 1
--       and 
--       b.temprature < a.temprature;
select 
    w2.id
from 
    Weather w1 join Weather w2
where 
    datediff(w2.recordDate,w1.recordDate) = 1
    and
    w1.temperature < w2.temperature;

