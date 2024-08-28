# Write your MySQL query statement below
with cte as (
    select pid, tiv_2015, tiv_2016,
    count(pid) over(partition by tiv_2015) as t15,
    count(pid) over(partition by lat,lon) as t16
    from Insurance
)
select round(sum(tiv_2016),2) as tiv_2016 from cte
where t15 >1 and t16 = 1;