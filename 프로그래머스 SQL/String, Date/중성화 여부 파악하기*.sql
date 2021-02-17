SELECT ANIMAL_ID, NAME, IF(SEX_UPON_INTAKE LIKE 'Neutered %' OR SEX_UPON_INTAKE LIKE 'Spayed %', 'O', 'X') AS '중성화'
FROM ANIMAL_INS

/*
IF문을 쓸 수 있다.
IF(조건, 조건에 맞을 때 표기하고 싶은 값, 조건과 맞지 않을 때 표기하고 싶은 값)
*/
