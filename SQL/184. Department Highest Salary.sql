SELECT
    d.name AS Department,
    e.name AS Employee,
    e.salary AS Salary
FROM
    Employee e
JOIN
    Department d ON e.departmentId = d.id
JOIN
    (
        SELECT
            departmentId,
            MAX(salary) AS max_salary
        FROM
            Employee
        GROUP BY
            departmentId
    ) max_salary_emp ON e.departmentId = max_salary_emp.departmentId AND e.salary = max_salary_emp.max_salary;