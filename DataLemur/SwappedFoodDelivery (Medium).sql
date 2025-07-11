/*
Source: https://datalemur.com/questions/sql-swapped-food-delivery
Diff: Medium

Zomato is a leading online food delivery service that connects users with various restaurants and cuisines, 
allowing them to browse menus, place orders, and get meals delivered to their doorsteps.

Recently, Zomato encountered an issue with their delivery system. Due to an error in the delivery driver instructions, 
each item's order was swapped with the item in the subsequent row. As a data analyst, you're asked to correct this 
swapping error and return the proper pairing of order ID and item.

If the last item has an odd order ID, it should remain as the last item in the corrected data. For example, 
if the last item is Order ID 7 Tandoori Chicken, then it should remain as Order ID 7 in the corrected data.

In the results, return the correct pairs of order IDs and items.

orders Schema:
column_name	type	description
order_id	integer	The ID of each Zomato order.
item	string	The name of the food item in each order.
orders Example Input:
Here's a sample of the initial incorrect data:

order_id	item
1	        Chow Mein
2	        Pizza
3	        Pad Thai
4	        Butter Chicken
5	        Eggrolls
6	        Burger
7	        Tandoori Chicken

orders Example Output:
The corrected data should look like this:
corrected_order_id	item
1	                Pizza
2	                Chow Mein
3	                Butter Chicken
4	                Pad Thai
5	                Burger
6	                Eggrolls
7	                Tandoori Chicken

Order ID 1 is now associated with Pizza and Order ID 2 is paired with Chow Mein. This adjustment ensures that each 
order is correctly aligned with its respective item, addressing the initial swapping error.

Order ID 7 remains unchanged and is still associated with Tandoori Chicken. This preserves the order sequence 
ensuring that the last odd order ID remains unaltered.
*/

-- My Solution
-- Planning Time: 0.211 ms
-- Execution Time: 0.093 ms
WITH paired AS (
    SELECT 
        *,
        (id - 1) / 2 AS pair_id
    FROM orders
),
numbered_pair AS (
    SELECT 
        *,
        ROW_NUMBER() OVER (PARTITION BY pair_id ORDER BY order_id DESC) as rn
    FROM paired
)
SELECT
    ROW_NUMBER() OVER () AS corrected_order_id,
    item
FROM numbered_pair
order by pair_id, rn

-- Editorial
-- Planning Time: 0.093 ms
-- Execution Time: 0.065 ms
WITH order_counts AS (
    SELECT COUNT(order_id) AS total_orders 
    FROM orders
)
SELECT
    CASE
        WHEN order_id % 2 != 0 AND order_id != total_orders THEN order_id + 1
        WHEN order_id % 2 != 0 AND order_id = total_orders THEN order_id
        ELSE order_id - 1
    END AS corrected_order_id,
    item
FROM orders
CROSS JOIN order_counts
ORDER BY corrected_order_id;