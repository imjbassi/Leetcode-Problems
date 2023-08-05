(
  SELECT 
    u.name AS results 
  from 
    movierating mr 
    INNER JOIN users u ON mr.user_id = u.user_id 
  GROUP BY 
    mr.user_id 
  ORDER BY 
    count(movie_id) DESC, 
    u.name 
  LIMIT 
    1
) 
UNION ALL 
  (
    SELECT 
      m.title AS results 
    from 
      movierating mr 
      INNER JOIN movies m ON mr.movie_id = m.movie_id 
    WHERE 
      month(mr.created_at)= 02 
      AND year(mr.created_at)= 2020 
    GROUP BY 
      mr.movie_id 
    ORDER BY 
      avg(mr.rating) DESC, 
      m.title 
    LIMIT 
      1
  )
  