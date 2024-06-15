# Write your MySQL query statement below

select 'Low Salary' as category, (select count(*) from Accounts where income < 20000) as accounts_count
union
select 'Average Salary' as category, (select count(*) from Accounts where income between  20000 and  50000) as accounts_count
union
select 'High Salary' as category, (select count(*) from Accounts where income > 50000) as accounts_count;