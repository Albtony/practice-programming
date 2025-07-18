/*
Source: https://leetcode.com/problems/game-play-analysis-iv/description/
Diff: Medium
Dialect: PostgreSQL

Table: Activity
+--------------+---------+
| Column Name  | Type    |
+--------------+---------+
| player_id    | int     |
| device_id    | int     |
| event_date   | date    |
| games_played | int     |
+--------------+---------+
(player_id, event_date) is the primary key (combination of columns with unique values) of this table.
This table shows the activity of players of some games.
Each row is a record of a player who logged in and played a number of games (possibly 0) before logging out on someday using some device.

Write a solution to report the fraction of players that logged in again on the day after the day they first logged in, rounded to 2 decimal places. 
In other words, you need to count the number of players that logged in for at least two consecutive days starting from their first login date, then divide that number by the total number of players.
The result format is in the following example.

Example 1:
Input: 
Activity table:
+-----------+-----------+------------+--------------+
| player_id | device_id | event_date | games_played |
+-----------+-----------+------------+--------------+
| 1         | 2         | 2016-03-01 | 5            |
| 1         | 2         | 2016-03-02 | 6            |
| 2         | 3         | 2017-06-25 | 1            |
| 3         | 1         | 2016-03-02 | 0            |
| 3         | 4         | 2018-07-03 | 5            |
+-----------+-----------+------------+--------------+

Output: 
+-----------+
| fraction  |
+-----------+
| 0.33      |
+-----------+
Explanation: 
Only the player with id 1 logged back in after the first day he had logged in so the answer is 1/3 = 0.33
*/

WITH ranked AS (
    SELECT 
        *,
        DENSE_RANK() OVER (PARTITION BY player_id ORDER BY event_date) AS drank
    FROM Activity
),
flagged AS (
    SELECT DISTINCT 
        player_id, 
        event_date,
        event_date - LAG(event_date) OVER (PARTITION BY player_id ORDER BY event_date) AS diff
    FROM ranked
    WHERE drank <= 2
    ORDER BY player_id
)
SELECT 
    ROUND(
        COUNT(DISTINCT player_id) FILTER(WHERE diff = 1)::DECIMAL /
        COUNT(DISTINCT player_id),
    2) AS fraction
FROM flagged