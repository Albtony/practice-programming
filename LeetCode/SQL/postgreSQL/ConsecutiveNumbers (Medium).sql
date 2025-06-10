/*
Source: https://leetcode.com/problems/consecutive-numbers/
Diff: Medium
Dialect: PostgreSQL
Pandas Schema
Table: Logs

+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| id          | int     |
| num         | varchar |
+-------------+---------+
In SQL, id is the primary key for this table.
id is an autoincrement column starting from 1.

Find all numbers that appear at least three times consecutively.
Return the result table in any order.
The result format is in the following example.

Example 1:

Input: 
Logs table:
+----+-----+
| id | num |
+----+-----+
| 1  | 1   |
| 2  | 1   |
| 3  | 1   |
| 4  | 2   |
| 5  | 1   |
| 6  | 2   |
| 7  | 2   |
+----+-----+
Output: 
+-----------------+
| ConsecutiveNums |
+-----------------+
| 1               |
+-----------------+

Explanation: 1 is the only number that appears consecutively for at least three times.
*/

SELECT DISTINCT a.num AS ConsecutiveNums
FROM Logs a
JOIN Logs b
ON a.id = b.id + 1
JOIN Logs c
ON a.id = c.id + 2
WHERE a.num = b.num AND a.num = c.num;

WITH intermediate AS (
    SELECT
        LAG(num) OVER (ORDER BY id)AS prev,
        num AS curr,
        LEAD(num) OVER (ORDER BY id) AS next
    FROM Logs
)
SELECT DISTINCT curr AS ConsecutiveNums
FROM intermediate
WHERE curr = prev AND curr = next;