-- https://leetcode.com/problems/suspicious-bank-accounts/
SELECT DISTINCT a1.account_id
FROM 
    (SELECT *
    FROM 
        (SELECT DISTINCT a.account_id ,
         a.yearMonth yearMonth
        FROM 
            (SELECT account_id,
         EXTRACT(YEAR_MONTH
            FROM day) yearMonth, sum(amount) total_income
            FROM Transactions
            WHERE type = 'Creditor'
            GROUP BY  account_id, EXTRACT(YEAR_MONTH
            FROM day)) a, Accounts b
            WHERE a.account_id = b.account_id
                    AND a.total_income>b.max_income) lo) a1 , 
            (SELECT *
            FROM 
                (SELECT DISTINCT c.account_id ,
         c.yearMonth yearMonth
                FROM 
                    (SELECT account_id,
         EXTRACT(YEAR_MONTH
                    FROM day) yearMonth, sum(amount) total_income
                    FROM Transactions
                    WHERE type = 'Creditor'
                    GROUP BY  account_id, EXTRACT(YEAR_MONTH
                    FROM day)) c, Accounts d
                    WHERE c.account_id = d.account_id
                            AND c.total_income> d.max_income) up) a2
                WHERE a1.yearMonth = a2.yearMonth + 1
                AND a1.account_id = a2.account_id