/*
Source: https://leetcode.com/problems/product-price-at-a-given-date/
Diff: Medium
Dialect: SQL Server

Table: Products
+---------------+---------+
| Column Name   | Type    |
+---------------+---------+
| product_id    | int     |
| new_price     | int     |
| change_date   | date    |
+---------------+---------+
(product_id, change_date) is the primary key (combination of columns with unique values) of this table.
Each row of this table indicates that the price of some product was changed to a new price at some date.

Write a solution to find the prices of all products on 2019-08-16. Assume the price of all products before any change is 10.
Return the result table in any order.
The result format is in the following example.

Example 1:
Input: 
Products table:
+------------+-----------+-------------+
| product_id | new_price | change_date |
+------------+-----------+-------------+
| 1          | 20        | 2019-08-14  |
| 2          | 50        | 2019-08-14  |
| 1          | 30        | 2019-08-15  |
| 1          | 35        | 2019-08-16  |
| 2          | 65        | 2019-08-17  |
| 3          | 20        | 2019-08-18  |
+------------+-----------+-------------+

Output: 
+------------+-------+
| product_id | price |
+------------+-------+
| 2          | 50    |
| 1          | 35    |
| 3          | 10    |
+------------+-------+
*/

WITH numbered AS (
    SELECT 
        product_id,
        change_date,
        ROW_NUMBER() OVER (PARTITION BY product_id ORDER BY change_date DESC) AS rn
    FROM products
    WHERE change_date <= '2019-08-16'
),
last_change AS (
    SELECT 
        p.product_id,
        p.change_date,
        p.new_price
    FROM products p
    JOIN numbered n
    ON 
        p.product_id = n.product_id AND
        p.change_date = n.change_date
    WHERE rn = 1
),
all_products AS (
    SELECT DISTINCT product_id
    FROM products
)
SELECT 
    a.product_id,
    COALESCE(l.new_price, 10) AS price
FROM last_change l
RIGHT JOIN all_products a
ON l.product_id = a.product_id

-- more concise version
WITH last_change AS (
    SELECT 
        product_id,
        new_price,
        ROW_NUMBER() OVER (
            PARTITION BY product_id 
            ORDER BY change_date DESC
        ) AS rn
    FROM products
    WHERE change_date <= '2019-08-16'
)
SELECT
    p.product_id,
    COALESCE(l.new_price, 10) AS price
FROM (
    SELECT DISTINCT product_id
    FROM products
) AS p
LEFT JOIN last_change AS l
    ON p.product_id = l.product_id
    AND l.rn = 1;
