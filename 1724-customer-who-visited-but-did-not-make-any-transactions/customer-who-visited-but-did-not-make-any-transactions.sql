select distinct(v.customer_id), count(v.visit_id) as count_no_trans 
from Visits v where v.visit_id not in(
    select c.visit_id from Visits c
     join Transactions t
    on c.visit_id = t.visit_id
) group by v.customer_id;


