#include<cstdio>
#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
#include<queue>
using namespace std;

/*
dp는 제일 싫은 문제 중에 하나다. 하지만 안하면 코테 떨어짐.. 특히 it 쪽 회사는...

책 보면서 제대로 몰랐던 내용이 있어서 옮겨 적어본다.

탑다운(메모이제이션) 방식은 하향식
보텀업 방식은 상향식.
다이나믹 프로그래밍의 전형적 형태는 보텀업.
보텀업 방식에서 사용되는 결과 저장용 리스트를 dp 테이블이라 하고
메모이제이션은 탑다운 방식에 국한되어 사용되는 표현이다.
메모이제이션은 이전에 계산된 결과를 임시적으로 기록해놓은 넓은 개념을 의미하므로 다이나믹 프로그래밍과 별도의 개념이다.
*/

/*
문제)
정수 X에 사용할 수 있는 연산은 다음과 같이 세 가지 이다.

1. X가 5로 나누어 떨어지면 5로 나눈다.
2. X가 3으로 나누어 떨어지면, 3으로 나눈다.
3. X가 2로 나누어 떨어지면, 2로 나눈다.
4. 1을 뺀다.

정수 N이 주어졌을 때, 위와 같은 연산 네 개를 적절히 사용해서 1을 만들려고 한다. 연산을 사용하는 횟수의 최솟값을 출력하시오.
*/

int x;
int dp[30001];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> x;
	for (int i = 2; i <= x; i++) {
		dp[i] = dp[i - 1] + 1;
		if (i % 2 == 0) dp[i] = min(dp[i], dp[i / 2] + 1);
		if (i % 3 == 0) dp[i] = min(dp[i], dp[i / 3] + 1);
		if (i % 5 == 0) dp[i] = min(dp[i], dp[i / 5] + 1);
	}

	cout << dp[x] << '\n';

	return 0;
}
