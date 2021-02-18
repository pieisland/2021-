/*
보호소에 들어올 당시에는 중성화되지 않았지만, 보호소를 나갈 당시에는 중성화된 동물의 
아이디와 생물 종, 이름을 조회하는 아이디 순으로 조회하는 SQL 문을 작성해주세요.
*/

SELECT AO.ANIMAL_ID, AO.ANIMAL_TYPE, AO.NAME
FROM ANIMAL_INS AS AI JOIN ANIMAL_OUTS AS AO ON AI.ANIMAL_ID = AO.ANIMAL_ID
WHERE AI.SEX_UPON_INTAKE LIKE 'Intact%' AND (AO.SEX_UPON_OUTCOME LIKE 'Spayed%' OR AO.SEX_UPON_OUTCOME LIKE 'Neutered%')
ORDER BY AO.ANIMAL_ID

/*
복잡하다..

WHERE 절에 어떤 값이 들어가는 것을 찾고 싶을 때 LIKE를 쓸 수 있다.
'ABC%'라 하면 ABC가 들어가고 그 뒤에 어떤 것도 올 수 있다는 의미이다. 
*/
