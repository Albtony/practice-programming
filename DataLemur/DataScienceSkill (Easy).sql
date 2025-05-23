/*
Source: https://datalemur.com/questions/matching-skills
Diff: easy

Given a table of candidates and their skills, you're tasked with finding the candidates best suited for an open Data Science job. 
You want to find candidates who are proficient in Python, Tableau, and PostgreSQL.

Write a query to list the candidates who possess all of the required skills for the job. Sort the output by candidate ID in ascending order.

Assumption:
There are no duplicates in the candidates table.

candidates Table:
Column Name	Type
candidate_id	integer
skill	varchar

candidates Example Input:
candidate_id	skill
123	            Python
123	            Tableau
123	            PostgreSQL
234	            R
234	            PowerBI
234	            SQL Server
345	            Python
345	            Tableau

Example Output:
candidate_id
123

Explanation
Candidate 123 is displayed because they have Python, Tableau, and PostgreSQL skills. 345 isn't included in the output because 
they're missing one of the required skills: PostgreSQL.7
*/

-- My Solution
-- Planning Time: 0.270 ms
-- Execution Time: 0.074 ms
SELECT candidate_id
FROM (SELECT candidate_id, encoded_skill
    FROM (SELECT candidate_id, CASE WHEN skill = 'Python' OR skill = 'Tableau' OR skill = 'PostgreSQL' THEN 1 ELSE 0 END AS encoded_skill
        FROM candidates
    ) AS candidates_norm
    WHERE encoded_skill = 1
) AS candidate_relevant_skill
GROUP BY candidate_id
ORDER BY COUNT(*) DESC
LIMIT 1;

-- Editorial
-- Planning Time: 0.094 ms
-- Execution Time: 0.053 ms
SELECT candidate_id
FROM candidates
WHERE skill IN ('Python', 'Tableau', 'PostgreSQL')
GROUP BY candidate_id
HAVING COUNT(skill) = 3
ORDER BY candidate_id;