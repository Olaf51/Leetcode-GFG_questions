# Write your MySQL query statement below
#SELECT c.name as Customers
#FROM Customers as c
#LEFT JOIN Orders as o
#ON  c.id = o.customerId
#where o.id is NULL;
Select Customers.name as Customers
FROM Customers
Where Customers.id NOT IN
(SELECT c.id
FROM Customers as c
inner join Orders as o
ON c.id = o.customerId
);
#name can be same but id cannot be