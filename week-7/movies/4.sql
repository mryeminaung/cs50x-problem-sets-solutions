-- 4. Number of movies with a 10.0 rating
SELECT COUNT(*) AS NumberOfMovies
FROM ratings
WHERE rating = 10.0;
