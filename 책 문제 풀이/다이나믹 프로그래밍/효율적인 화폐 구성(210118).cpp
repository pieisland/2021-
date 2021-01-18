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
해설을 보니, 
1부터 하는 게 아니라
돈의 종류를 첫 번째 for문으로 사용해서
두 번째 for문의 시작 값을 해당 돈 값으로 시작하네.
이러면 양수다 뭐다 따질 필요가 없긴 하다.

이거 for문 순서 바꿔서 값이 달라지는 것도 있었던 걸로 기억하는데.
이 문제에서 순서가 달라도 같은 종류를 사용했으면 같은 거라고 했고
어차피 합을 만드는 최소의 동전 개수를 구하는 거라서.. 의미 없는 것 같기도 하다.
...싫은 문제.
*/

int n, m;
int money[101];
int dp[10001];
int INF = 987654321;

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;

	for (int i = 0; i <= m; i++) {
		dp[i] = INF;
	}

	for (int i = 1; i <= n; i++) {
		cin >> money[i];
		dp[money[i]] = 1;
	}

	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			if (i - money[j] > 0) {
				if (dp[i - money[j]] + 1 < dp[i]) {
					dp[i] = dp[i - money[j]] + 1;
				}
			}
		}
	}

	if (dp[m] == INF) {
		cout << -1 << '\n';
	}
	else cout << dp[m] << '\n';

	return 0;
}
