/*
09:00부터 19:59까지, 각 시간대별로 입양이 몇 건이나 발생했는지 조회하는 SQL문을 작성해주세요.
이때 결과는 시간대 순으로 정렬해야 합니다.
*/

SELECT HOUR(DATETIME), IFNULL(COUNT(HOUR(DATETIME)), 0)
FROM ANIMAL_OUTS
WHERE HOUR(DATETIME) BETWEEN 9 TO 19
GROUP BY HOUR(DATETIME)
ORDER BY HOUR(DATETIME)

/*
시간에 대해서 한 시간 간격으로 해야하기 때문에 DATETIME에 HOUR라는 것을 사용했습니다.
WHERE 로 먼저 원하는 시간대를 거른 다음에 그룹을 지으면 된다.
IFNULL이라는 게 있는데 IFNULL(조건, 해당 조건이 NULL일 때 보여줄 값)을 적어주면 된다.

BETWEEN을 사용해서 어느 범위에 있는 값만 걸러올 수 있다.
*/
