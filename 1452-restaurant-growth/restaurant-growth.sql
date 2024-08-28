# Write your MySQL query statement below
-- with cte as (
--     select  sum(amount)  as day_sum, visited_on
--     from Customer 
--     group by visited_on
--     order by visited_on
-- )

-- select visited_on,
-- sum(day_sum) over(rows between 6 preceding  and current row) as amount,
-- round(avg(day_sum) over(rows between 6 preceding  and current row),2) as average_amount
-- from cte
-- OFFSET 6


WITH 
cte1 AS (
    SELECT visited_on, SUM(amount) AS amount
    FROM Customer
    GROUP BY visited_on
),
cte2 AS (
    SELECT 
        visited_on,
        SUM(amount) OVER (ORDER BY visited_on ROWS BETWEEN 6 PRECEDING AND CURRENT ROW) AS amount
    FROM cte1 
)

SELECT visited_on, amount, ROUND(amount / 7, 2) AS average_amount
FROM cte2
WHERE visited_on > (SELECT MIN(visited_on) FROM cte1) + INTERVAL 5 DAY