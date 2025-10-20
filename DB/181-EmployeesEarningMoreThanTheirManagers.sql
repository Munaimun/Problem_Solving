select a.name
AS Employee
from
    Employee AS a,
    Employee AS b
where
    a.managerId = b.id
    AND a.salary > b.salary
;