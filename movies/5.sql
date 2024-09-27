SELECT title, year
FROM movies
WHERE id =
(
    SELECT id
    FROM people
    WHERE name = 'Harry Potter'
)
LIKE '%Harry Potter%.'
ORDER BY year;
