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
테스트케이스
4 11
1 5 6 9
*/

/*
그 책에 있던 문제랑 그냥 똑같다.

뭔가 최솟값을 구할 때 dp 값 초기로 max 넣어줘야 하는 그런 느낌이라 해야되나.
최댓값 찾는 문제랑 최솟값 찾는 문제들...
*/

int coins[20];
int dp[10001];

int n;
int m;

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	for (int i = 0; i <= 10000; i++)
		dp[i] = 987654321;
	
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> coins[i];
		dp[coins[i]] = 1;
	}

	for (int i = 1; i <= m; i++) {
		for (int j = 0; j < n; j++) {
			if (i - coins[j] > 0) {
				if (dp[i - coins[j]] + 1 < dp[i])
					dp[i] = dp[i - coins[j]] + 1;
			}
		}
	}

	for (int i = 1; i <= m; i++) {
		cout << dp[i] << ' ';
	}
	cout << endl;
	cout << dp[m];

	return 0;
}
