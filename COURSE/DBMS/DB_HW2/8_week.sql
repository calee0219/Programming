SELECT CASE DayOfWeek
    WHEN 1 THEN 'MONDAY'
    WHEN 2 THEN 'TUESDAY'
    WHEN 3 THEN 'WEDNESDAY'
    WHEN 4 THEN 'THURSDAY'
    WHEN 5 THEN 'FRIDAY'
    WHEN 6 THEN 'SATURDAY'
    WHEN 7 THEN 'SUNDAY'
END AS DayOfWeek , AVG(DepDelay)
FROM records
GROUP BY DayOfWeek;