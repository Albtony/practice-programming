/*
Source: https://datalemur.com/questions/duplicate-job-listings
Diff: Easy

Assume you're given a table containing job postings from various companies on the LinkedIn platform. Write a query to 
retrieve the count of companies that have posted duplicate job listings.

Definition:
Duplicate job listings are defined as two job listings within the same company that share identical titles and descriptions.

job_listings Table:
Column      Name	Type
job_id	    integer
company_id	integer
title	    string
description	string

job_listings Example Input:
job_id	company_id	title	description
248	827	Business Analyst	Business analyst evaluates past and current business data with the primary goal of improving decision-making processes within organizations.
149	845	Business Analyst	Business analyst evaluates past and current business data with the primary goal of improving decision-making processes within organizations.
945	345	Data Analyst	    Data analyst reviews data to identify key insights into a business's customers and ways the data can be used to solve problems.
164	345	Data Analyst	    Data analyst reviews data to identify key insights into a business's customers and ways the data can be used to solve problems.
172	244	Data Engineer	    Data engineer works in a variety of settings to build systems that collect, manage, and convert raw data into usable information for data scientists and business analysts to interpret.

Example Output:
duplicate_companies
1

Explanation:
There is one company ID 345 that posted duplicate job listings. The duplicate listings, IDs 945 and 164 have identical titles and descriptions.
*/

-- My Solution
-- Planning Time: 0.087 ms
-- Execution Time: 0.049 ms
SELECT COUNT(*) as duplicate_companies -- count it
FROM (
    -- find companies with duplicate listing
    SELECT COUNT(*) 
    FROM job_listings
    GROUP BY company_id, title
    HAVING COUNT(*) > 1
) AS sub

-- Editorial 1
-- Planning Time: 0.214 ms
-- Execution Time: 0.063 ms
WITH job_count_cte AS (
    SELECT 
        company_id, 
        title, 
        description, 
        COUNT(job_id) AS job_count
    FROM job_listings
    GROUP BY company_id, title, description
)
SELECT COUNT(DISTINCT company_id) AS duplicate_companies
FROM job_count_cte
WHERE job_count > 1;

-- Editorial 2
-- Planning Time: 0.096 ms
-- Execution Time: 0.065 ms
SELECT COUNT(DISTINCT company_id) AS duplicate_companies
FROM (
    SELECT 
        company_id, 
        title, 
        description, 
        COUNT(job_id) AS job_count
    FROM job_listings
    GROUP BY company_id, title, description
) AS job_count_cte
WHERE job_count > 1;