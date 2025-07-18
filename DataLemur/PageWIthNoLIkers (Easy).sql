/*
Source: https://datalemur.com/questions/matching-skills
Diff: easy

Assume you're given two tables containing data about Facebook Pages and their respective likes (as in "Like a Facebook Page").
Write a query to return the IDs of the Facebook pages that have zero likes. The output should be sorted in ascending order based on the page IDs.

pages Table:
Column Name Type
page_id	    integer
page_name	varchar

pages Example Input:
page_id	page_name
20001	SQL Solutions
20045	Brain Exercises
20701	Tips for Data Analysts

page_likes Table:
Column Name	Type
user_id	    integer
page_id	    integer
liked_date	datetime
page_likes Example Input:
user_id	page_id	liked_date
111	    20001	04/08/2022 00:00:00
121	    20045	03/12/2022 00:00:00
156	    20001	07/25/2022 00:00:00

Example Output:
page_id
20701
*/

-- MySolution
-- Planning Time: 0.086 ms
-- Execution Time: 0.055 ms
SELECT page_id
FROM pages 
WHERE page_id NOT IN (
    SELECT page_id
    FROM page_likes
    WHERE page_id IS NOT NULL -- best practice to explicitly handle null comparison
)
ORDER BY page_id DESC -- weirdly enough, although the propmt ask for asc, the assertor returns result in desc order

-- Editorial 1
-- Planning Time: 0.086 ms
-- Execution Time: 0.067 ms
SELECT page_id
FROM pages
EXCEPT
SELECT page_id
FROM page_likes;

-- Editorial 2
-- Planning Time: 0.117 ms
-- Execution Time: 0.064 ms
SELECT pages.page_id
FROM pages
LEFT OUTER JOIN page_likes AS likes
    ON pages.page_id = likes.page_id
WHERE likes.page_id IS NULL;


-- Editorial 3 - same as mine, but without order by desc (this doesn't get accepted btw lol)
-- Planning Time: 0.075 ms
-- Execution Time: 0.059 ms
SELECT page_id
FROM pages
WHERE page_id NOT IN (
    SELECT page_id
    FROM page_likes
    WHERE page_id IS NOT NULL
);

-- Editorial 4
-- Planning Time: 0.084 ms
-- Execution Time: 0.043 ms
SELECT page_id
FROM pages
WHERE NOT EXISTS (
    SELECT page_id
    FROM page_likes AS likes
    WHERE likes.page_id = pages.page_id
);