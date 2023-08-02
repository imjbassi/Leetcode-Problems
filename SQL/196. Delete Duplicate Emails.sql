WITH CTE AS (
    SELECT email, MIN(id) AS min_id
    FROM Person
    GROUP BY email
)
DELETE p
FROM Person p
JOIN CTE c ON p.email = c.email
WHERE p.id > c.min_id;