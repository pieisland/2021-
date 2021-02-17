/*
입양을 간 기록은 있는데, 보호소에 들어온 기록이 없는 동물의 ID와 이름을 ID 순으로 조회하는 SQL문을 작성해주세요.
*/

SELECT ANIMAL_OUTS.ANIMAL_ID, ANIMAL_OUTS.NAME
FROM ANIMAL_INS RIGHT OUTER JOIN ANIMAL_OUTS ON ANIMAL_INS.ANIMAL_ID = ANIMAL_OUTS.ANIMAL_ID
WHERE ANIMAL_INS.ANIMAL_ID IS NULL
ORDER BY ANIMAL_OUTS.ANIMAL_ID

/*
- JOIN 대상 테이블들을 적고 어떤 조인을 할건지도(INNER JOIN, OUTER JOIN.. LEFT.. RIGHT) 적은 후 ON에 어떤 값을 기준으로 할 건지 적어준다.
- 이 문제에서 WHERE에 NAME 적었다가 틀렸는데, ... ID를 적어야 하는거란다.
- JOIN이 왜이리 안 익숙한지 모르겠다. 풀 때 ON을 써야하는 사실도 잊음.
*/
