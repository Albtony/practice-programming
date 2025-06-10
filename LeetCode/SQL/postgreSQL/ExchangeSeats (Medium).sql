/*
Source: https://leetcode.com/problems/exchange-seats/description/
Diff: Medium
Dialect: PostgreSQL

Table: Seat
+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| id          | int     |
| student     | varchar |
+-------------+---------+
id is the primary key (unique value) column for this table.
Each row of this table indicates the name and the ID of a student.
The ID sequence always starts from 1 and increments continuously.

Write a solution to swap the seat id of every two consecutive students. If the number of students is odd, the id of the last student is not swapped.
Return the result table ordered by id in ascending order.
The result format is in the following example.

Example 1:

Input: 
Seat table:
+----+---------+
| id | student |
+----+---------+
| 1  | Abbot   |
| 2  | Doris   |
| 3  | Emerson |
| 4  | Green   |
| 5  | Jeames  |
+----+---------+

Output: 
+----+---------+
| id | student |
+----+---------+
| 1  | Doris   |
| 2  | Abbot   |
| 3  | Green   |
| 4  | Emerson |
| 5  | Jeames  |
+----+---------+

Explanation: 
Note that if the number of students is odd, there is no need to change the last one's seat.
*/

WITH paired AS (
    SELECT 
        *,
        (id - 1) / 2 AS pair
    FROM Seat
),
swapped AS (
    SELECT
        *,
        ROW_NUMBER() OVER (PARTITION BY pair ORDER BY id DESC) as ordr
    FROM paired
)
SELECT 
    ROW_NUMBER() OVER () as id,
    student
FROM swapped
ORDER by pair, ordr