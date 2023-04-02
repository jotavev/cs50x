SELECT movies.title FROM movies 
JOIN stars ON stars.movie_id = movies.id
JOIN people ON stars.person_id = people.id AND people.name = "Johnny Depp"
JOIN stars stars2 ON stars2.movie_id = movies.id
JOIN people people2 ON stars2.person_id = people2.id AND people2.name = "Helena Bonham Carter";
