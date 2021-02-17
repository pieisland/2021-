/*
입양을 간 동물 중, 보호 기간이 가장 길었던 동물 두 마리의 아이디와 이름을 조회하는 SQL문을 작성해주세요. 
이때 결과는 보호 기간이 긴 순으로 조회해야 합니다.
*/

SELECT AO.ANIMAL_ID, AO.NAME
FROM ANIMAL_INS AI JOIN ANIMAL_OUTS AO ON AI.ANIMAL_ID = AO.ANIMAL_ID
ORDER BY AO.DATETIME - AI.DATETIME DESC
LIMIT 2

/*
보호 기간을 계산하기 위해 JOIN이 필요하다.
그리고 DATETIME은 - + 연산을 할 수 있나보다. 그냥 - 해서 보호기간을 구할 수 있고, 긴 순으로 조회해야 하므로 DESC를 썼다.
*/
