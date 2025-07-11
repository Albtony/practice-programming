/*
Source: https://datalemur.com/questions/prime-warehouse-storage
Diff: Hard

Amazon wants to maximize the storage capacity of its 500,000 square-foot warehouse by prioritizing a specific batch of 
prime items. The specific prime product batch detailed in the inventory table must be maintained.
So, if the prime product batch specified in the item_category column included 1 laptop and 1 side table, that would be 
the base batch. We could not add another laptop without also adding a side table; they come all together as a batch set.

After prioritizing the maximum number of prime batches, any remaining square footage will be utilized to stock non-prime 
batches, which also come in batch sets and cannot be separated into individual items.
Write a query to find the maximum number of prime and non-prime batches that can be stored in the 500,000 square feet 
warehouse based on the following criteria:

Prioritize stocking prime batches
After accommodating prime items, allocate any remaining space to non-prime batches
Output the item_type with prime_eligible first followed by not_prime, along with the maximum number of batches that can be stocked.

Assumptions:
Again, products must be stocked in batches, so we want to find the largest available quantity of prime batches, and then the largest 
available quantity of non-prime batches
Non-prime items must always be available in stock to meet customer demand, so the non-prime item count should never be zero.
Item count should be whole numbers (integers).

inventory table:
Column Name	    Type
item_id	        integer
item_type	    string
item_category	string
square_footage	decimal

inventory Example Input:
item_id	item_type	    item_category	    square_footage
1374	prime_eligible	mini refrigerator	68.00
4245	not_prime	    standing lamp	    26.40
2452	prime_eligible	television	        85.00
3255	not_prime	    side table	        22.60
1672	prime_eligible	laptop	            8.50

Example Output:
item_type	    item_count
prime_eligible	9285
not_prime	    6
*/
-- My Solution
-- Planning Time: 0.128 ms
-- Execution Time: 0.154 ms
WITH stats AS (
    SELECT
        500000.0 AS available_square,
        COUNT(*) FILTER(WHERE item_type = 'prime_eligible') AS total_primes,
        COUNT(*) FILTER(WHERE item_type = 'not_prime') AS total_non_primes,
        SUM(square_footage) FILTER(WHERE item_type = 'prime_eligible') AS prime_footage,
        SUM(square_footage) FILTER(WHERE item_type = 'not_prime') AS non_prime_footage
    FROM inventory
),
calc AS (
    SELECT
        FLOOR(available_square / prime_footage) * total_primes AS prime_eligible,
        FLOOR(MOD(available_square, prime_footage) / non_prime_footage) * total_non_primes AS not_prime
    FROM stats
)

SELECT   
    'prime_eligible' AS item_type,
    prime_eligible AS item_count
FROM calc
UNION ALL
SELECT
    'not_prime' AS item_type,
    not_prime AS item_count
FROM calc

-- Editorial 
-- Planning Time: 0.162 ms
-- Execution Time: 0.060 ms
WITH summary AS (
    SELECT 
        SUM(square_footage) FILTER (WHERE item_type = 'prime_eligible') AS prime_sq_ft,
        COUNT(item_id) FILTER (WHERE item_type = 'prime_eligible') AS prime_item_count,
        SUM(square_footage) FILTER (WHERE item_type = 'not_prime') AS not_prime_sq_ft,
        COUNT(item_id) FILTER (WHERE item_type = 'not_prime') AS not_prime_item_count
    FROM inventory
),
prime_occupied_area AS (
    SELECT FLOOR(500000/prime_sq_ft)*prime_sq_ft AS max_prime_area
    FROM summary
)

SELECT 
    'prime_eligible' AS item_type,
    FLOOR(500000/prime_sq_ft)*prime_item_count AS item_count
FROM summary
UNION ALL
SELECT 
    'not_prime' AS item_type,
    FLOOR((500000-(SELECT max_prime_area FROM prime_occupied_area)) 
        / not_prime_sq_ft) * not_prime_item_count AS item_count
FROM summary;