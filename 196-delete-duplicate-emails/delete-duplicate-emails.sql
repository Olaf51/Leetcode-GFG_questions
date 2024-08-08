# Write your MySQL query statement below
delete p.*
from Person p, (
    select email, min(id) as minId
    from person
    group by email
    having count(*)>1
) as t
where p.email = t.email and p.id > t.minId;