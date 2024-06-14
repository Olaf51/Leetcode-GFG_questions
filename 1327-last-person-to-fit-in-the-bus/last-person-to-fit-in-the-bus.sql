# Write your MySQL query statement below
select person_name from (
select * , sum(weight) over(order by turn rows between unbounded preceding and current row) as total from Queue) t
where total <= 1000
order by total desc
limit 1;

