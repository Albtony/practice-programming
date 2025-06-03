/*
Source: https://datalemur.com/questions/median-search-freq
Diff: Hard

Google's marketing team is making a Superbowl commercial and needs a simple statistic to put on their TV ad: the median number 
of searches a person made last year.

However, at Google scale, querying the 2 trillion searches is too costly. Luckily, you have access to the summary table 
which tells you the number of searches made last year and how many Google users fall into that bucket.

Write a query to report the median of searches made by a user. Round the median to one decimal point.

search_frequency Table:
Column Name	Type
searches	integer
num_users	integer

search_frequency Example Input:
searches	num_users
1	        2
2	        2
3	        3
4	        1

Example Output:
median
2.5

By expanding the search_frequency table, we get [1, 1, 2, 2, 3, 3, 3, 4] which has a median of 2.5 searches per user.
*/
-- My Solution (Algorithmic)
-- Planning Time: 0.208 ms
-- Execution Time: 0.126 ms
WITH running AS (
    SELECT 
        *,
        SUM(num_users) OVER (ORDER BY searches) AS running_total
    FROM search_frequency
),
stats AS (
    SELECT 
        *,
        ROUND(MAX(running_total) OVER () / 2.0, 1) AS median_index
    FROM running
),
median_index AS (
    SELECT DISTINCT median_index 
    FROM stats
)
SELECT
    CASE
        WHEN MOD(median_index, 1) != 0 THEN (
        SELECT searches
        FROM stats
        WHERE running_total >= median_index
        LIMIT 1    
        )
        WHEN MOD(median_index, 1) = 0 THEN (
        SELECT ROUND(AVG(searches), 1)
        FROM (
            SELECT searches
            FROM stats
            WHERE running_total >= median_index
            ORDER BY running_total
            LIMIT 2
        ) AS med_rows
        )
    END AS median
FROM median_index

-- Editorial (Brute forc with generate_series())
-- Planning Time: 0.115 ms
-- Execution Time: 0.284 ms
WITH searches_expanded AS (
    SELECT searches
    FROM search_frequency
    GROUP BY 
        searches, 
        GENERATE_SERIES(1, num_users))
SELECT 
    ROUND(PERCENTILE_CONT(0.50) WITHIN GROUP (
        ORDER BY searches)::DECIMAL, 1) AS  median
FROM searches_expanded;