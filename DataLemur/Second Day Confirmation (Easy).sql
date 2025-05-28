/*
Source: https://datalemur.com/questions/second-day-confirmation
DIff: Easy

Assume you're given tables with information about TikTok user sign-ups and confirmations through email and text. 
New users on TikTok sign up using their email addresses, and upon sign-up, each user receives a text message confirmation to activate their account.
Write a query to display the user IDs of those who did not confirm their sign-up on the first day, but confirmed on the second day.

Definition:
action_date refers to the date when users activated their accounts and confirmed their sign-up through text messages.

emails Table:
Column Name	Type
email_id	integer
user_id 	integer
signup_date	datetime

emails Example Input:
email_id	user_id	signup_date
125	        7771	06/14/2022 00:00:00
433	        1052	07/09/2022 00:00:00

texts Table:
Column Name	    Type
text_id	        integer
email_id	    integer
signup_action	string ('Confirmed', 'Not confirmed')
action_date	    datetime

texts Example Input:
text_id	email_id	signup_action	action_date
6878	125	        Confirmed	    06/14/2022 00:00:00
6997	433	        Not Confirmed	07/09/2022 00:00:00
7000	433	        Confirmed	    07/10/2022 00:00:00

Example Output:
user_id
1052

Explanation:
Only User 1052 confirmed their sign-up on the second day.
*/

-- My Solution
-- Planning Time: 0.286 ms
-- Execution Time: 0.089 ms 
WITH numbered AS (
    SELECT 
        *,
        ROW_NUMBER() OVER (PARTITION BY email_id ORDER BY action_date) AS rn
    FROM  texts
)
SELECT e.user_id 
FROM emails e
JOIN numbered n
ON n.email_id = e.email_id
WHERE n.rn = 2 AND n.signup_action = 'Confirmed'
-- Editorial solution is better performance, correctness, and readability wise
-- Only use ROW_NUMBER() for positional logic, not time-based logic
-- for time-based logic, its better to use Interval

-- Editorial
-- Planning Time: 0.272 ms
-- Execution Time: 0.065 ms
SELECT DISTINCT user_id
FROM emails 
INNER JOIN texts
    ON emails.email_id = texts.email_id
WHERE texts.action_date = emails.signup_date + INTERVAL '1 day'
    AND texts.signup_action = 'Confirmed';