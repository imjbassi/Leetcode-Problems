SELECT product_id, product_name
FROM Product
WHERE product_id NOT IN (
    SELECT DISTINCT s.product_id
        FROM Sales s
            WHERE s.sale_date >= '2019-04-01' OR s.sale_date < '2019-01-01'
            ) AND product_id IN (
                SELECT DISTINCT s.product_id
                    FROM Sales s
                        WHERE s.sale_date >= '2019-01-01' AND s.sale_date <= '2019-03-31'
                        );
                        