/*
동물 보호소에 들어온 동물 중 이름이 Lucy, Ella, Pickle, Rogan, Sabrina, Mitty인 동물의 
아이디와 이름, 성별 및 중성화 여부를 조회하는 SQL 문을 작성해주세요.
*/

SELECT ANIMAL_ID, NAME, SEX_UPON_INTAKE
FROM ANIMAL_INS
WHERE NAME IN ("Lucy", "Ella", "Pickle", "Sabrina", "Mitty")
ORDER BY ANIMAL_ID

/*
IN 안에 해당하는 값들을 넣어주면 그 값일 경우 SELECT 된다.
물론 = "" 해서 해도 되지만, 대상이 많을 때는 IN을 쓰는 게 편할 것이다.
*/
