SELECT t.request_at AS Day, ROUND(COUNT(CASE WHEN t.status LIKE 'cancelled%' THEN 1 END) / COUNT(*) , 2) 
AS `Cancellation Rate`
FROM Trips t
JOIN Users u1 ON t.client_id = u1.users_id AND u1.banned = 'No'
JOIN Users u2 ON t.driver_id = u2.users_id AND u2.banned = 'No'
WHERE t.request_at BETWEEN '2013-10-01' AND '2013-10-03'
GROUP BY t.request_at;