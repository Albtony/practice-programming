/*
Source: https://datalemur.com/questions/alibaba-compressed-mean
DIff: Easy

You're trying to find the mean number of items per order on Alibaba, rounded to 1 decimal place using tables which includes information 
on the count of items in each order (item_count table) and the corresponding number of orders for each item count (order_occurrences table).

items_per_order Table:
Column Name	        Type
item_count	        integer
order_occurrences	integer

items_per_order Example Input:
item_count	order_occurrences
1	        500
2	        1000
3	        800
4	        1000

There are a total of 500 orders with one item per order, 1000 orders with two items per order, and 800 orders with three items per order."

Example Output:
mean
2.7
Explanation
Let's calculate the arithmetic average:

Total items = (1*500) + (2*1000) + (3*800) + (4*1000) = 8900
Total orders = 500 + 1000 + 800 + 1000 = 3300
Mean = 8900 / 3300 = 2.7
*/

-- My Solution
-- Planning Time: 0.395 ms
-- Execution Time: 0.099 ms
SELECT 
    ROUND(
        CAST(
            SUM(item_count * order_occurrences) / 
            SUM(order_occurrences) AS NUMERIC
        ),
    1) AS mean
FROM items_per_order;

-- Editorial
-- Planning Time: 0.037 ms
-- Execution Time: 0.059 ms
SELECT 
    ROUND(
        SUM(item_count::DECIMAL*order_occurrences)
        /SUM(order_occurrences)
    ,1) AS mean
FROM items_per_order;