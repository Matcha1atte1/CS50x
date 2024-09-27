SELECT title, year
FROM movies
JOIN people ON movies.id = people.id
WHERE people.name
LIKE '%Harry Potter%.'
ORDER BY year;
