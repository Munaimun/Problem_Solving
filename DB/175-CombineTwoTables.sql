-- This query retrieves information about people along with their addresses.
-- using a LEFT JOIN so that even if a person does not have an address, their information will still appear in the result set.

SELECT
    firstName,   -- Person's first name
    lastName,    -- Person's last name
    city,        -- City from Address table (can be NULL if no matching address)
    state        -- State from Address table (can be NULL if no matching address)
FROM 
    Person
LEFT JOIN 
    Address
ON 
    Person.personId = Address.personId;  -- Match rows where personId is the same
