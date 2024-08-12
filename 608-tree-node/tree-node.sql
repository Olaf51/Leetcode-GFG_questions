# Write your MySQL query statement below
select id, CASE WHEN p_id IS NULL THEN "Root"
             When id IN (SELECT p_id from Tree) THEN "Inner"
             ELSE "Leaf"
             END as type
    from Tree
