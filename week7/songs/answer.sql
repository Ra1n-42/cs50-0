SELECT
    AVG(danceability) AS avg_danceability,
    AVG(energy) AS avg_energy,
    AVG(key) AS avg_key,
    AVG(loudness) AS avg_loudness,
    AVG(speechiness) AS avg_speechiness,
    AVG(valence) AS avg_valence,
    AVG(tempo) AS avg_tempo,
    AVG(duration_ms)/60000 AS avg_duration_min
FROM
    songs;

SELECT * from songs;
