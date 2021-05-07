SELECT Id, Month, a.
FROM  SELECT e.Id,
         e.Month,
         e.Salary
        FROM Employee e, 
            (SELECT Id,
         Max(Month) max_month
            FROM Employee
            GROUP BY  Id) a
            WHERE e.Id = a.Id
                    AND e.Month <> a.max_month) m, 
                (SELECT e1.Id,
         MAX(e1.Month) max_m
                FROM Employee e1, 
                    (SELECT Id,
         Max(Month) max_month
                    FROM Employee
                    GROUP BY  Id) a
                    WHERE e1.Id = a.Id
                            AND e1.Month <> a.max_month
                    GROUP BY  e1.Id) n
                    WHERE m.Id = n.Id
                            AND m.Month= n.max_m-2) a, 
                    (SELECT m.Id,
         m.Month,
         SUM(m.Salary)
                        OVER (order by m.Id, m.Month) AS Salary
                    FROM 
                        (SELECT e.Id,
         e.Month,
         e.Salary
                        FROM Employee e, 
                            (SELECT Id,
         Max(Month) max_month
                            FROM Employee
                            GROUP BY  Id) a
                            WHERE e.Id = a.Id
                                    AND e.Month <> a.max_month) m, 
                                (SELECT e1.Id,
         MAX(e1.Month) max_m
                                FROM Employee e1, 
                                    (SELECT Id,
         Max(Month) max_month
                                    FROM Employee
                                    GROUP BY  Id) a
                                    WHERE e1.Id = a.Id
                                            AND e1.Month <> a.max_month
                                    GROUP BY  e1.Id) n
                                    WHERE m.Id = n.Id
                                            AND m.Month = n.max_m-1) b, 
                                    (SELECT m.Id,
         m.Month,
         SUM(m.Salary)
                                        OVER (order by m.Id, m.Month) AS Salary
                                    FROM 
                                        (SELECT e.Id,
         e.Month,
         e.Salary
                                        FROM Employee e, 
                                            (SELECT Id,
         Max(Month) max_month
                                            FROM Employee
                                            GROUP BY  Id) a
                                            WHERE e.Id = a.Id
                                                    AND e.Month <> a.max_month) m, 
                                                (SELECT e1.Id,
         MAX(e1.Month) max_m
                                                FROM Employee e1, 
                                                    (SELECT Id,
         Max(Month) max_month
                                                    FROM Employee
                                                    GROUP BY  Id) a
                                                    WHERE e1.Id = a.Id
                                                            AND e1.Month <> a.max_month
                                                    GROUP BY  e1.Id) n
                                                    WHERE m.Id = n.Id
                                                            AND m.Month= n.max_m) c
                                                ORDER BY  Id asc, Month DESC