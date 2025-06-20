/*
Source:
Diff: Easy

Assume you have an events table on Facebook app analytics. Write a query to calculate the click-through rate (CTR) for the 
app in 2022 and round the results to 2 decimal places.

Definition and note:
Percentage of click-through rate (CTR) = 100.0 * Number of clicks / Number of impressions
To avoid integer division, multiply the CTR by 100.0, not 100.

events Table:
Column Name	Type
app_id	    integer
event_type	string
timestamp	datetime

events Example Input:
app_id	event_type	timestamp
123	    impression	07/18/2022 11:36:12
123	    impression	07/18/2022 11:37:12
123	    click	    07/18/2022 11:37:42
234	    impression	07/18/2022 14:15:12
234	    click	    07/18/2022 14:16:12

Example Output:
app_id	ctr
123	    50.00
234	    100.00

Explanation
Let's consider an example of App 123. This app has a click-through rate (CTR) of 50.00% because out of the 2 impressions it received, it got 1 click.

To calculate the CTR, we divide the number of clicks by the number of impressions, and then multiply the result by 100.0 to express it as a percentage. 
In this case, 1 divided by 2 equals 0.5, and when multiplied by 100.0, it becomes 50.00%. So, the CTR of App 123 is 50.00%.
*/

-- My Solution
-- Planning Time: 0.069 ms
-- Execution Time: 0.051 ms
SELECT 
    app_id, 
    ROUND(
        100.0 * 
        COUNT(*) FILTER(WHERE event_type = 'click') / 
        COUNT(*) FILTER(WHERE event_type = 'impression')
    , 2) AS ctr
FROM events
WHERE EXTRACT(YEAR FROM timestamp) = 2022 --
GROUP BY app_id

-- Editorial 1
-- Planning Time: 0.092 ms
-- Execution Time: 0.062 ms
SELECT
    app_id,
    ROUND(100.0 *
        SUM(CASE WHEN event_type = 'click' THEN 1 ELSE 0 END) /
        SUM(CASE WHEN event_type = 'impression' THEN 1 ELSE 0 END), 2)  AS ctr_rate
FROM events
WHERE timestamp >= '2022-01-01' 
    AND timestamp < '2023-01-01'
GROUP BY app_id;

-- Editorial 2
-- Planning Time: 0.068 ms
-- Execution Time: 0.056 ms
SELECT
    app_id,
    ROUND(100.0 *
        COUNT(CASE WHEN event_type = 'click' THEN 1 ELSE NULL END) /
        COUNT(CASE WHEN event_type = 'impression' THEN 1 ELSE NULL END), 2)  AS ctr_rate
FROM events
WHERE timestamp >= '2022-01-01' 
    AND timestamp < '2023-01-01'
GROUP BY app_id;

-- Editorial 3
-- Planning Time: 0.090 ms
-- Execution Time: 0.094 ms
EXPLAIN ANALYSE
SELECT
    app_id,
    ROUND(100.0 *
        SUM(1) FILTER (WHERE event_type = 'click') /
        SUM(1) FILTER (WHERE event_type = 'impression'), 2) AS ctr_app
FROM events
WHERE timestamp >= '2022-01-01' 
    AND timestamp < '2023-01-01'
GROUP BY app_id;