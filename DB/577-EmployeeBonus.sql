-- Problem Statement:
-- We have two tables: Employee and Bonus.
-- We need to return every employee whose bonus is either LESS than 1000 OR completely missing (NULL).
-- Output columns → name, bonus.

-- Time Complexity:
-- O(N) — single LEFT JOIN scan, where N is the number of employee rows.
-- Space Complexity:
-- O(1) — no extra data structures created.

-- Query:
SELECT e.name, b.bonus
FROM Employee e
LEFT JOIN Bonus b
    ON e.empId = b.empId  -- match each employee with bonus if exists
WHERE b.bonus < 1000      -- employees with small bonus
   OR b.bonus IS NULL;    -- OR employees with no bonus at all
