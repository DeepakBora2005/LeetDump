CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
  RETURN (
    SELECT salary AS getNthHighestSalary 
    FROM Employee
    ORDER BY salary DESC
    LIMIT 1
  );
END