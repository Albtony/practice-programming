/*
Source: https://datalemur.com/questions/sql-highest-grossing
Diff: Medium

This is the same question as problem #12 in the SQL Chapter of Ace the Data Science Interview!

Assume you're given a table containing data on Amazon customers and their spending on products in different category,
write a query to identify the top two highest-grossing products within each category in the year 2022. The output should 
include the category, product, and total spend.

product_spend Table:
Column Name	        Type
category	        string
product	            string
user_id	            integer
spend	            decimal
transaction_date	timestamp

product_spend Example Input:
category	product	user_id	    spend	    transaction_date
appliance	refrigerator	    165	246.00	12/26/2021 12:00:00
appliance	refrigerator	    123	299.99	03/02/2022 12:00:00
appliance	washing machine	    123	219.80	03/02/2022 12:00:00
electronics	vacuum	            178	152.00	04/05/2022 12:00:00
electronics	wireless headset	156	249.90	07/08/2022 12:00:00
electronics	vacuum	            145	189.00	07/15/2022 12:00:00

Example Output:
category	product	            total_spend
appliance	refrigerator	    299.99
appliance	washing machine	    219.80
electronics	vacuum	            341.00
electronics	wireless headset	249.90

Explanation:
Within the "appliance" category, the top two highest-grossing products are "refrigerator" and "washing machine."
In the "electronics" category, the top two highest-grossing products are "vacuum" and "wireless headset."
*/

-- My Solution
-- Planning Time: 0.383 ms
-- Execution Time: 0.097 ms
WITH numbered AS (
    SELECT 
        category, 
        product, 
        SUM(spend) AS total_spend,
        ROW_NUMBER() OVER (PARTITION BY category ORDER BY SUM(spend) DESC) AS rn
    FROM product_spend
    WHERE 
        transaction_date >= '2022-01-01' AND
        transaction_date < '2023-01-01'
    GROUP BY category, product
)
SELECT category, product, total_spend
FROM numbered
WHERE rn <= 2
ORDER BY category, total_spend DESC

-- Editorial
-- Planning Time: 0.130 ms
-- Execution Time: 0.102 ms
SELECT 
    category, 
    product, 
    total_spend 
    FROM (
    SELECT 
        category, 
        product, 
        SUM(spend) AS total_spend,
        RANK() OVER (
        PARTITION BY category 
        ORDER BY SUM(spend) DESC) AS ranking 
    FROM product_spend
    WHERE EXTRACT(YEAR FROM transaction_date) = 2022
    GROUP BY category, product
) AS ranked_spending
WHERE ranking <= 2 
ORDER BY category, ranking;