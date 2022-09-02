# Write your MySQL query statement below
Select t1.name as Customers from Customers t1
where t1.id not in (select customerId from Orders)