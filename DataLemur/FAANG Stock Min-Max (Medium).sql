/*
The Bloomberg terminal is the go-to resource for financial professionals, offering convenient access to a wide array 
of financial datasets. As a Data Analyst at Bloomberg, you have access to historical data on stock performance.

Currently, you're analyzing the highest and lowest open prices for each FAANG stock by month over the years.
For each FAANG stock, display the ticker symbol, the month and year ('Mon-YYYY') with the corresponding highest 
and lowest open prices (refer to the Example Output format). Ensure that the results are sorted by ticker symbol.

stock_prices Schema:
Column Name	Type	    Description
date	    datetime	The specified date (mm/dd/yyyy) of the stock data.
ticker	    varchar	    The stock ticker symbol (e.g., AAPL) for the corresponding company.
open	    decimal	    The opening price of the stock at the start of the trading day.
high	    decimal	    The highest price reached by the stock during the trading day.
low	        decimal	    The lowest price reached by the stock during the trading day.
close	    decimal	    The closing price of the stock at the end of the trading day.

stock_prices Example Input:
Note that the table below displays randomly selected AAPL data.

date	            ticker	open	high	low	    close
01/31/2023 00:00:00	AAPL	142.28	142.70	144.34	144.29
02/28/2023 00:00:00	AAPL	146.83	147.05	149.08	147.41
03/31/2023 00:00:00	AAPL	161.91	162.44	165.00	164.90
04/30/2023 00:00:00	AAPL	167.88	168.49	169.85	169.68
05/31/2023 00:00:00	AAPL	176.76	177.33	179.35	177.25

Example Output:
ticker	highest_mth	highest_open	lowest_mth	lowest_open
AAPL	May-2023	176.76	        Jan-2023	142.28

Apple Inc. (AAPL) achieved its highest opening price of $176.76 in May 2023 and its lowest opening price of $142.28 in January 2023.
*/

-- My Solution
-- Planning Time: 0.202 ms
-- Execution Time: 1.569 ms
WITH highest AS (
    SELECT 
        ticker,
        open,
        date,
        DENSE_RANK() OVER (PARTITION BY ticker ORDER BY open DESC) as high_rank
    FROM stock_prices
),
lowest AS (
    SELECT 
        ticker,
        open,
        date,
        DENSE_RANK() OVER (PARTITION BY ticker ORDER BY open ASC) as low_rank
    FROM stock_prices
)
SELECT 
    h.ticker,
    TO_CHAR(h.date, 'Mon-YYYY') AS highest_mth,
    h.open AS highest_open,
    TO_CHAR(l.date, 'Mon-YYYY') AS lowest_mth,
    l.open AS lowest_open
FROM highest h
JOIN lowest l
ON 
    h.ticker = l.ticker AND
    h.high_rank = 1 AND 
    l.low_rank = 1
-- rank condition is executed on join, reducing intermediary table entries from unecessary join

-- Editorial
-- Planning Time: 0.191 ms
-- Execution Time: 1.817 ms
Explain ANALYSE
WITH highest_prices AS (
    SELECT 
        ticker,
        TO_CHAR(date, 'Mon-YYYY') AS highest_mth,
        MAX(open) AS highest_open,
        ROW_NUMBER() OVER (PARTITION BY ticker ORDER BY open DESC) AS row_num
    FROM stock_prices
    GROUP BY ticker, TO_CHAR(date, 'Mon-YYYY'), open
),
lowest_prices AS (
    SELECT 
        ticker,
        TO_CHAR(date, 'Mon-YYYY') AS lowest_mth,
        MIN(open) AS lowest_open,
        ROW_NUMBER() OVER (PARTITION BY ticker ORDER BY open) AS row_num
    FROM stock_prices
    GROUP BY ticker, TO_CHAR(date, 'Mon-YYYY'), open
)
SELECT
    highest.ticker,
    highest.highest_mth,
    highest.highest_open,
    lowest.lowest_mth,
    lowest.lowest_open
FROM highest_prices as highest
INNER JOIN lowest_prices AS lowest
    ON highest.ticker = lowest.ticker
    AND highest.row_num = 1 -- Highest open price
    AND lowest.row_num = 1 -- Lowest open price
ORDER BY highest.ticker;