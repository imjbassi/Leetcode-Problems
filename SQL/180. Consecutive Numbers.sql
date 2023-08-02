SELECT DISTINCT num AS ConsecutiveNums
FROM (
    SELECT num,
    LEAD(num) OVER (ORDER BY id) AS next_num,
    LAG(num) OVER (ORDER BY id) as prev_num
    FROM Logs
    ) AS TEMP
WHERE num = next_num AND num = prev_num;