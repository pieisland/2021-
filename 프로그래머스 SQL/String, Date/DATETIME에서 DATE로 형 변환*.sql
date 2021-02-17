SELECT ANIMAL_ID, NAME, DATE_FORMAT(DATETIME, '%Y-%m-%d')
FROM ANIMAL_INS
ORDER BY ANIMAL_ID

/*
DATETIME을 문자열로 바꿔준다. DATE로 형변환.. 이라기보다는 문자열로 바꾸었는데
그럴 때 DATE_FORMAT이라는 함수를 사용한다. 
%Y를 해야 숫자 네 개 연도 가 나오고 소문자를 쓰면 두 자리가 나온다.
%m이 숫자로, %M이 문자로 나온다.
%d가 숫자로, %D가 1st, 2nd 이런 식으로 나온다.

원하는 형식은 2021-02-17 이런 형태였기 때문에 '%Y-%m-%d'를 사용한다.
*/
