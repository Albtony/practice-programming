/*
Source: https://datalemur.com/questions/supercloud-customer
Diff: Medium

A Microsoft Azure Supercloud customer is defined as a customer who has purchased at least one product from every product 
category listed in the products table.

Write a query that identifies the customer IDs of these Supercloud customers.

customer_contracts Table:
Column Name	Type
customer_id	integer
product_id	integer
amount	    integer

customer_contracts Example Input:
customer_id	product_id	amount
1	        1	        1000
1	        3	        2000
1	        5	        1500
2	        2	        3000
2	        6	        2000

products Table:
Column Name	        Type
product_id	        integer
product_category	string
product_name	    string

products Example Input:
product_id	product_category	product_name
1	        Analytics	        Azure Databricks
2	        Analytics	        Azure Stream Analytics
4	        Containers	        Azure Kubernetes Service
5	        Containers	        Azure Service Fabric
6	        Compute	            Virtual Machines
7	        Compute	            Azure Functions

Example Output:
customer_id
1

Explanation:
Customer 1 bought from Analytics, Containers, and Compute categories of Azure, and thus is a Supercloud customer. 
Customer 2 isn't a Supercloud customer, since they don't buy any container services from Azure.
*/

-- My Solution
-- Planning Time: 0.117 ms
-- Execution Time: 0.077 ms
WITH user_bought_category AS (
    SELECT DISTINCT c.customer_id, p.product_category 
    FROM customer_contracts c
    JOIN products p
    ON c.product_id = p.product_id
)
SELECT u.customer_id
FROM user_bought_category u
GROUP BY u.customer_id
HAVING COUNT(u.product_category) = (
    SELECT COUNT(DISTINCT product_category)
    FROM products
)

-- Editorial
-- Planning Time: 0.154 ms
-- Execution Time: 0.091 ms
WITH supercloud_cust AS (
    SELECT 
        customers.customer_id, 
        COUNT(DISTINCT products.product_category) AS product_count
    FROM customer_contracts AS customers
    INNER JOIN products 
        ON customers.product_id = products.product_id
    GROUP BY customers.customer_id
)
SELECT customer_id
FROM supercloud_cust
WHERE product_count = (
    SELECT COUNT(DISTINCT product_category) FROM products
);