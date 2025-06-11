/*
Source: https://leetcode.com/problems/find-students-who-improved/
Diff: Medium
Dialect: SQL Server

Table: Scores
+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| student_id  | int     |
| subject     | varchar |
| score       | int     |
| exam_date   | varchar |
+-------------+---------+
(student_id, subject, exam_date) is the primary key for this table.
Each row contains information about a student's score in a specific subject on a particular exam date. score is between 0 and 100 (inclusive).
Write a solution to find the students who have shown improvement. A student is considered to have shown improvement if they meet both 
of these conditions:

Have taken exams in the same subject on at least two different dates
Their latest score in that subject is higher than their first score
Return the result table ordered by student_id, subject in ascending order.

The result format is in the following example.

Example:
Input:
Scores table:
+------------+----------+-------+------------+
| student_id | subject  | score | exam_date  |
+------------+----------+-------+------------+
| 101        | Math     | 70    | 2023-01-15 |
| 101        | Math     | 85    | 2023-02-15 |
| 101        | Physics  | 65    | 2023-01-15 |
| 101        | Physics  | 60    | 2023-02-15 |
| 102        | Math     | 80    | 2023-01-15 |
| 102        | Math     | 85    | 2023-02-15 |
| 103        | Math     | 90    | 2023-01-15 |
| 104        | Physics  | 75    | 2023-01-15 |
| 104        | Physics  | 85    | 2023-02-15 |
+------------+----------+-------+------------+

Output:
+------------+----------+-------------+--------------+
| student_id | subject  | first_score | latest_score |
+------------+----------+-------------+--------------+
| 101        | Math     | 70          | 85           |
| 102        | Math     | 80          | 85           |
| 104        | Physics  | 75          | 85           |
+------------+----------+-------------+--------------+

Explanation:
Student 101 in Math: Improved from 70 to 85
Student 101 in Physics: No improvement (dropped from 65 to 60)
Student 102 in Math: Improved from 80 to 85
Student 103 in Math: Only one exam, not eligible
Student 104 in Physics: Improved from 75 to 85
Result table is ordered by student_id, subject.
*/

WITH numbered AS (
    SELECT
        *,
        ROW_NUMBER() OVER (PARTITION BY student_id, subject ORDER BY exam_date) rn_asc,
        ROW_NUMBER() OVER (PARTITION BY student_id, subject ORDER BY exam_date DESC) rn_desc
    FROM scores
)
SELECT n1.student_id, n1.subject, n1.score AS first_score, n2.score AS latest_score
FROM numbered n1
JOIN numbered n2
ON 
    n1.student_id = n2.student_id AND
    n1.rn_asc = 1 AND 
    n2.rn_desc = 1 AND
    n1.subject = n2.subject AND
    n1.exam_date <> n2.exam_date
WHERE n1.score < n2.score