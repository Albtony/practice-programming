/*
Source: https://datalemur.com/questions/sql-top-three-salaries
Diff: Medium

As part of an ongoing analysis of salary distribution within the company, your manager has requested a report 
identifying high earners in each department. A 'high earner' within a department is defined as an employee with 
a salary ranking among the top three salaries within that department.

You're tasked with identifying these high earners across all departments. Write a query to display the employee's 
name along with their department name and salary. In case of duplicates, sort the results of department name in 
ascending order, then by salary in descending order. If multiple employees have the same salary, then order them alphabetically.

Note: Ensure to utilize the appropriate ranking window function to handle duplicate salaries effectively.
As of June 18th, we have removed the requirement for unique salaries and revised the sorting order for the results.

employee Schema:
column_name	    type	description
employee_id	    integer	The unique ID of the employee.
name	        string	The name of the employee.
salary	        integer	The salary of the employee.
department_id	integer	The department ID of the employee.
manager_id	    integer	The manager ID of the employee.

employee Example Input:
employee_id	name	    salary	department_id	manager_id
1	Emma Thompson	    3800	1	            6
2	Daniel Rodriguez	2230	1	            7
3	Olivia Smith	    2000	1	            8
4	Noah Johnson	    6800	2	            9
5	Sophia Martinez	    1750	1	            11
6	Liam Brown	        13000	3	
7	Ava Garcia	        12500	3	
8	William Davis	    6800	2	
9	Isabella Wilson	    11000	3	
10	James Anderson	    4000	1	            11

department Schema:
column_name	type	description
department_id	integer	The department ID of the employee.
department_name	string	The name of the department.

department Example Input:
department_id	department_name
1	Data Analytics
2	Data Science

Example Output:
department_name	name	            salary
Data Analytics	James Anderson	    4000
Data Analytics	Emma Thompson	    3800
Data Analytics	Daniel Rodriguez	2230
Data Science	Noah Johnson	    6800
Data Science	William Davis	    6800
*/

-- My Solution 
-- Planning Time: 0.163 ms
-- Execution Time: 0.160 ms
WITH ranked AS (
    SELECT 
        d.department_name,
        e.name,
        e.salary,
        -- better to do the ranking like how editorial did it, department_id is easier to iterate and index upon, better performance
        DENSE_RANK() OVER (PARTITION BY d.department_name ORDER BY e.salary DESC) as rank
    FROM employee e 
    JOIN department d
    ON e.department_id = d.department_id
)
SELECT  department_name, name, salary
FROM ranked
WHERE rank <= 3
ORDER BY department_name, salary DESC, name

-- Editorial
-- Planning Time: 0.109 ms
-- Execution Time: 0.170 ms
WITH ranked_salary AS (
    SELECT 
        name,
        salary,
        department_id,
        DENSE_RANK() OVER (
        PARTITION BY department_id ORDER BY salary DESC) AS ranking
    FROM employee
)

SELECT 
    d.department_name,
    s.name,
    s.salary
FROM ranked_salary AS s
INNER JOIN department AS d
    ON s.department_id = d.department_id
WHERE s.ranking <= 3
ORDER BY d.department_name ASC, s.salary DESC, s.name ASC;