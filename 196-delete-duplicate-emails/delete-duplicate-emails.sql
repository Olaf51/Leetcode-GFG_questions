# Write your MySQL query statement below
delete Person from Person 
where id in
(
    select a.id
    from (
        select id, email,
        row_number() over(partition by email order by id) as rk
        from Person
    ) a
    where a.rk > 1
)