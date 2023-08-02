SELECT sp.name
FROM SalesPerson sp
LEFT JOIN Orders o ON sp.sales_id = o.sales_id AND o.com_id = (
    SELECT com_id FROM Company WHERE name = 'RED'
    )
    WHERE o.order_id IS NULL;