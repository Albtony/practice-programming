/*
Source: https://datalemur.com/questions/amazon-shopping-spree
Diff: Medium

In an effort to identify high-value customers, Amazon asked for your help to obtain data about 
users who go on shopping sprees. A shopping spree occurs when a user makes purchases on 3 or more consecutive days.

List the user IDs who have gone on at least 1 shopping spree in ascending order.

transactions Table:
Column Name	        Type
user_id	            integer
amount	            float
transaction_date	timestamp

transactions Example Input:
user_id	amount	transaction_date
1	    9.99	08/01/2022 10:00:00
1	    55	    08/17/2022 10:00:00
2	    149.5	08/05/2022 10:00:00
2	    4.89	08/06/2022 10:00:00
2	    34	    08/07/2022 10:00:00

Example Output:
user_id
2

Explanation
In this example, user_id 2 is the only one who has gone on a shopping spree.
*/

-- My Solution
-- Planning Time: 0.127 ms
-- Execution Time: 0.135 ms
WITH numbered AS (
    -- deduplicate multiple transaction on one date, use row number to calculate sequential time distance
    SELECT DISTINCT
        user_id,
        DATE(transaction_date) as date,
        ROW_NUMBER() OVER (PARTITION BY user_id ORDER BY DATE(transaction_date)) AS rn
    FROM transactions 
), 
calculated AS (
    -- translate transaction date based on time distance
    SELECT
        user_id,
        date - INTERVAL '1 day' * rn AS calc
    FROM numbered
)
-- sequential transaction will be translated to the same date, we can just count it now
SELECT user_id
FROM calculated
GROUP BY user_id, calc
HAVING COUNT(*) = 3
ORDER BY user_id

-- Editorial
-- Planning Time: 0.111 ms
-- Execution Time: 0.140 ms
SELECT DISTINCT T1.user_id
FROM transactions AS T1
INNER JOIN transactions AS T2
    ON DATE(T2.transaction_date) = DATE(T1.transaction_date) + 1
INNER JOIN transactions AS T3
    ON DATE(T3.transaction_date) = DATE(T1.transaction_date) + 2
ORDER BY T1.user_id;