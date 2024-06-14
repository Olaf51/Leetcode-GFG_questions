# Write your MySQL query statement below
-- with cte as (
--     select num,
--     lead(num,1) over(order by id) num1,
--     lead(num,2) over(order by id) num2
--     from Logs
-- )
-- select distinct num as ConsecutiveNums
-- from cte
-- where (num = num1) and (num = num2);
select distinct l1.num as ConsecutiveNums from Logs l1
join Logs l2 on l1.id = l2.id-1
join Logs l3 on l1.id = l3.id-2
where l1.num = l2.num and l1.num = l3.num;