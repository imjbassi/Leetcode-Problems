SELECT COALESCE(
      (SELECT num
          FROM (
                  SELECT num
                          FROM MyNumbers
                                  GROUP BY num
                                          HAVING COUNT(num) = 1
                                              ) AS single_numbers
                                                  ORDER BY num DESC
                                                      LIMIT 1),
                                                          NULL
                                                          ) AS num;