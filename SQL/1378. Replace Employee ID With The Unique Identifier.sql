SELECT EUNI.unique_id, E.name
FROM Employees E
LEFT JOIN EmployeeUNI EUNI ON E.id = EUNI.id;