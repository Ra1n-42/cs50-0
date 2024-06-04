SELECT DISTINCT people.name
FROM people
JOIN stars ON stars.person_id = people.id
JOIN movies ON movies.id = stars.movie_id
JOIN stars AS kb_stars ON kb_stars.movie_id = movies.id
JOIN people AS kb_person ON kb_person.id = kb_stars.person_id
WHERE kb_person.name = 'Kevin Bacon' AND kb_person.birth = 1958
AND people.name != 'Kevin Bacon';
