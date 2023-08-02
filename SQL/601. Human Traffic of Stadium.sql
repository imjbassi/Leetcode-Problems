SELECT id, visit_date, people
FROM (
  SELECT *, COUNT(*) OVER (PARTITION BY island) AS cnt
  FROM (
    SELECT *, id - ROW_NUMBER() OVER (ORDER BY id) AS island
    FROM Stadium
    WHERE people >= 100
  ) AS subquery
) AS subquery2
WHERE cnt >= 3
ORDER BY visit_date;