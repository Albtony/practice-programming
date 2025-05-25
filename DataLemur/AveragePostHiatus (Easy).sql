/*
Source: https://datalemur.com/questions/sql-average-post-hiatus-1
Diff: Easy

Given a table of Facebook posts, for each user who posted at least twice in 2021, write a query to find the number of days 
between each user’s first post of the year and last post of the year in the year 2021. Output the user and number of the days 
between each user's first and last post.

p.s. If you've read the Ace the Data Science Interview and liked it, consider writing us a review?

posts Table:
Column Name	    Type
user_id	        integer
post_id	        integer
post_content	text
post_date	    timestamp

posts Example Input:
user_id	post_id	post_content	        post_date
151652	599415	Need a hug	            07/10/2021 12:00:00
661093	624356	Bed. Class 8-12. ...    07/29/2021 13:00:00
004239	784254	Happy 4th of July!	    07/04/2021 11:00:00
661093	442560	Just going to cry ...	07/08/2021 14:00:00
151652	111766	I'm so done with ...    07/12/2021 19:00:00

Example Output:
user_id	days_between
151652	2
661093	21

*/

-- My Solution
-- Planning Time: 0.085 ms
-- Execution Time: 0.066 ms
SELECT 
    user_id, 
    EXTRACT(DAY FROM MAX(post_date) - MIN(post_date)) AS days_between
FROM posts
WHERE post_date BETWEEN '2021-01-01' AND '2021-12-31'
GROUP BY user_id
HAVING COUNT(*) > 1

-- Editorial 
-- Planning Time: 0.126 ms
-- Execution Time: 0.075 ms
SELECT 
	user_id, 
    MAX(post_date::DATE) - MIN(post_date::DATE) AS days_between
FROM posts
WHERE DATE_PART('year', post_date::DATE) = 2021 
GROUP BY user_id
HAVING COUNT(post_id)>1;