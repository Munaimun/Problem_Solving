# Write your MySQL query statement below
select email AS Email
from Person
group by Email
having count(Email) > 1
;