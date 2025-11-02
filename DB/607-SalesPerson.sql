/*
Problem Statement:
Find the names of all salespeople who have NOT made any sales to the company named 'RED'.

Approach:
1. Use a subquery to identify all salespeople who made sales to 'RED'.
2. Then, select all salespeople whose names are NOT in that list.

Time Complexity:
O(N + M + K)
- N = number of SalesPerson records
- M = number of Orders records
- K = number of Company records

Space Complexity:
O(N)
- Subquery result stored temporarily for filtering.
*/

-- Select the name of each salesperson
SELECT s.name
-- From the SalesPerson table, giving it the alias 's'
FROM SalesPerson s
-- Keep only those salespeople whose names are NOT in the subquery result
WHERE s.name NOT IN (
    -- Subquery begins here
    -- Select the names of salespeople who HAVE made sales to 'RED'
    SELECT s.name
    -- From the SalesPerson table again, aliased as 's'
    FROM SalesPerson s
    -- Join the Orders table on matching salesperson IDs
    LEFT JOIN Orders ord ON s.sales_id = ord.sales_id
    -- Join the Company table on matching company IDs from Orders
    LEFT JOIN Company c ON c.com_id = ord.com_id
    -- Filter only those orders made to the company named 'RED'
    WHERE c.name = 'RED'
);