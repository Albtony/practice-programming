/*
Your team at JPMorgan Chase is soon launching a new credit card. You are asked to estimate how many cards 
you'll issue in the first month.

Before you can answer this question, you want to first get some perspective on how well new credit card launches 
typically do in their first month.

Write a query that outputs the name of the credit card, and how many cards were issued in its launch month. T
he launch month is the earliest record in the monthly_cards_issued table for a given card. Order the results 
starting from the biggest issued amount.

monthly_cards_issued Table:
Column Name	    Type
issue_month	    integer
issue_year	    integer
card_name	    string
issued_amount	integer

monthly_cards_issued Example Input:
issue_month	issue_year	card_name	            issued_amount
1	        2021	    Chase Sapphire Reserve	170000
2	        2021	    Chase Sapphire Reserve	175000
3	        2021	    Chase Sapphire Reserve	180000
3	        2021	    Chase Freedom Flex	    65000
4	        2021	    Chase Freedom Flex	    70000

Example Output:
card_name	            issued_amount
Chase Sapphire Reserve	170000
Chase Freedom Flex	    65000

Explanation
Chase Sapphire Reserve card was launched on 1/2021 with an issued amount of 170,000 cards and the 
Chase Freedom Flex card was launched on 3/2021 with an issued amount of 65,000 cards.
*/

-- My Solution  
-- Planning Time: 0.192 ms
-- Execution Time: 0.101 ms
WITH normalized AS (
    SELECT  
        card_name,
        issued_amount, 
        MIN(MAKE_DATE(issue_year, issue_month, 1)) AS date
    FROM monthly_cards_issued
),
launch_date AS (
    SELECT 
        card_name,
        MIN(date) AS date
    FROM normalized
    GROUP BY card_name
)
SELECT n.card_name, n.issued_amount
FROM normalized n
JOIN launch_date l
ON 
    n.card_name = l.card_name AND
    n.date = l.date
ORDER BY n.issued_amount DESC


-- Editorial
-- Planning Time: 0.085 ms
-- Execution Time: 0.076 ms
WITH card_launch AS (
    SELECT 
        card_name,
        issued_amount,
        MAKE_DATE(issue_year, issue_month, 1) AS issue_date,
        MIN(MAKE_DATE(issue_year, issue_month, 1)) OVER (
        PARTITION BY card_name) AS launch_date
    FROM monthly_cards_issued
)

SELECT 
    card_name, 
    issued_amount
FROM card_launch
WHERE issue_date = launch_date
ORDER BY issued_amount DESC;