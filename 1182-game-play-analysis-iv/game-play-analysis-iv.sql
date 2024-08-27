# Write your MySQL query statement below





-- select round(count(distinct player_id)/(select count(distinct player_id) from Activity),2)
-- as fraction 
-- from Activity
-- where (player_id, date_sub(event_date, INTERVAL 1 DAY)) in
-- (select player_id, min(event_date) as first
-- from Activity 
-- group by player_id);
select round(sum(temp)/count(distinct player_id),2) as fraction from
(select
    player_id,
    datediff(event_date, min(event_date) over(partition by player_id)) = 1 as temp
  from 
    Activity) as t
