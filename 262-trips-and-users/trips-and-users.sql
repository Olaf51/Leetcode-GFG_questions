# Write your MySQL query statement below
select t.request_at as "Day",
round(sum(case when t.status <> 'completed' then 1 else 0 end)*1.0/count(*),2) as "Cancellation Rate"
from Trips t
join Users a
on t.client_id = a.users_id  
join Users b
on t.driver_id = b.users_id 
where
a.banned = 'No' and
b.banned = 'No' and
t.request_at between '2013-10-01' and '2013-10-03'
group by t.request_at
order by t.request_at