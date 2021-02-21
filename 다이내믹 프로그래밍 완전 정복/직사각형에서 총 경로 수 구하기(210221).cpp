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
(0,0)에셔 (n-1, m-1)로 가는 경로의 수 구하기.

초반에 맨 첫 열, 첫 행을 1로 채워주는 게 필요.
*/

int n, m;
int dp[301][301];

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;

	for (int i = 1; i < m; i++) {
		dp[0][i] = 1;
	}

	for (int i = 1; i < n; i++) {
		dp[i][0] = 1;
	}

	for (int i = 1; i < n; i++) {
		for (int j = 1; j < m; j++) {
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
		}
	}

	cout << dp[n - 1][m - 1];

	return 0;
}
