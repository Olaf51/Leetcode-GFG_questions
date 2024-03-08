# Write your MySQL query statement below

with cte as
(
    select customer_number, COUNT(order_number) as num
    from Orders
    Group by customer_number
)
select customer_number
from cte
where num = (SELECT MAX(num) from cte);
