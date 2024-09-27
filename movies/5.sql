SELECT title, year
FROM movies
JOIN stars ON movies.id = stars.movie_id
JOIN people ON stars.person_id = people.id
SELECT name
FROM people
WHERE name
LIKE '%Harry Potter%'
ORDER BY movies.year;
