#include<cstdio>
#include<stdio.h>
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>
#include<cmath>

using namespace std;

/*
위가 삭제, 왼쪽이 삽입, 왼쪽 위가 치환
이라고 한다.

어떤 책을 보든 이해가 안되게 쓰여있다.
..^0^ 이코테나 이 책이나 그냥 그렇다고 말하는데 나는 이해를 할 수가 없음.ㅋ
다 마음에 안 든다 진심..
*/

int dp[301][301];

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	string s1, s2;
	cin >> s1 >> s2;

	int n = s1.length();
	int m = s2.length();

	for (int i = 1; i <= m; i++) {
		dp[0][i] = i;
	}

	for (int i = 1; i <= n; i++) {
		dp[i][0] = i;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (s1[i - 1] == s2[j - 1]) {
				dp[i][j] = dp[i - 1][j - 1];
			}
			else {
				dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1]))+1;
			}
		}
	}

	cout << dp[n][m] << '\n';

	return 0;
}
