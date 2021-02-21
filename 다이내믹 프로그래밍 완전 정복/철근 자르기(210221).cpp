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
문제)
길이가 n인 철근을 팔아서 얻을 수 있는 이익의 최댓값.
*/

/*
테스트 케이스
8
1 5 8 9 10 17 17 20
답: 22
*/

/*
최댓값을 구하는 거라서 굳이 제일 작은 값을 넣거나 그러지 않아도 될 것.
*/

int n;
int value[301];
int dp[301];

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> value[i];
		dp[i] = value[i];
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j < i; j++) {
			dp[i] = max(dp[i], dp[i - j] + value[j]);
		}
	}

	cout << dp[n];

	return 0;
}
