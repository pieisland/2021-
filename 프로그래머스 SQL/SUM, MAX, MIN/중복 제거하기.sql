SELECT COUNT(DISTINCT NAME)
FROM ANIMAL_INS
WHERE NAME IS NOT NULL

/*DISTINCT로 중복되지 않는 것만 가져올 수 있다.
그리고 NULL과 관련해 IS NOT 을 사용할 수 있다. NULL인 것을 고르려면 IS NULL 하면 되고..*/
