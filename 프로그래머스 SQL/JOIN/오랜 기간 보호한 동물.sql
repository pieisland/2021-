/*
아직 입양을 못 간 동물 중, 가장 오래 보호소에 있었던 동물 3마리의 이름과 보호 시작일을 조회하는 SQL문을 작성해주세요. 
이때 결과는 보호 시작일 순으로 조회해야 합니다.
*/

SELECT AI.NAME, AI.DATETIME
FROM ANIMAL_INS AS AI LEFT OUTER JOIN ANIMAL_OUTS AS AO ON AI.ANIMAL_ID = AO.ANIMAL_ID
WHERE AO.ANIMAL_ID IS NULL
ORDER BY AI.DATETIME
LIMIT 3

/*
입양을 못 갔다는 건.. IN에는 있는데 OUT에는 없어야 하기 때문에.
IN을 기준으로 해서 가져와야 해서 LEFT OUTER JOIN을 사용했다.
그리고, WHERE 조건에 AO.ANIMAL_ID = NULL을 해서 입양 못 간 애를 선별한다.
*/
