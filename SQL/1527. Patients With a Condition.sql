SELECT patient_id, patient_name, conditions
FROM Patients
WHERE conditions LIKE '%DIAB100%'
ORDER BY patient_id;
