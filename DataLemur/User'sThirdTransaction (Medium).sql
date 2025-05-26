/*
Source: https://datalemur.com/questions/sql-third-transaction
Diff: Medium

Assume you are given the table below on Uber transactions made by users. Write a query to obtain the third transaction of every user. 
Output the user id, spend and transaction date.

transactions Table:
Column Name	        Type
user_id	            integer
spend	            decimal
transaction_date	timestamp

transactions Example Input:
user_id	spend	transaction_date
111	    100.50	01/08/2022 12:00:00
111	    55.00	01/10/2022 12:00:00
121	    36.00	01/18/2022 12:00:00
145	    24.99	01/26/2022 12:00:00
111	    89.60	02/05/2022 12:00:00

Example Output:
user_id	spend	transaction_date
111	    89.60	02/05/2022 12:00:00
*/

-- My Solution
-- Planning Time: 0.110 ms
-- Execution Time: 0.081 ms
WITH ranked AS (
    SELECT 
        user_id, 
        spend, 
        transaction_date,
        RANK() OVER (PARTITION BY user_id ORDER BY transaction_date) AS transaction_order -- should've use row number to avoid duplicates
    FROM transactions
    GROUP BY user_id, spend, transaction_date   -- no need to group since its already handled by partition clause
)
SELECT user_id, spend, transaction_date
FROM ranked
WHERE transaction_order = 3

-- Editorial 1
-- Planning Time: 0.337 ms
-- Execution Time: 0.110 ms
SELECT 
    user_id,
    spend,
    transaction_date
FROM (
    SELECT
        user_id, 
        spend, 
        transaction_date, 
        ROW_NUMBER() OVER (
        PARTITION BY user_id ORDER BY transaction_date) AS row_num
    FROM transactions) AS trans_num 
WHERE row_num = 3;

-- Editorial 2
-- Planning Time: 0.079 ms
-- Execution Time: 0.072 ms
WITH trans_num AS (
    SELECT 
        user_id, 
        spend, 
        transaction_date, 
        ROW_NUMBER() OVER (
        PARTITION BY user_id ORDER BY transaction_date) AS row_num 
    FROM transactions)
SELECT 
    user_id, 
    spend, 
    transaction_date 
FROM trans_num 
WHERE row_num = 3;