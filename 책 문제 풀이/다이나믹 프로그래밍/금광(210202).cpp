#include<cstdio>
#include<stdio.h>
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>

using namespace std;

/*
dp 계산할 때 행 열의 순서가 중요했다.
for문에서 열이 먼저 시작하고 행들에 대해 봐야한다.

다시 보니 이 문제 되게 신경써야 하는 문제였네..?
일반적인 문제랑은 좀 다른 것 같다.
대개는 dp[i][j] = max(dp[i-1][j-1], max(dp[i-1][j], dp[i][j-1])) 이게 많은데
게다가 행열에 대한 순서까지로 해줘야 하고..
움직이는 게 열로만 움직여서 그런 듯.
특정 열에 대해서 이 전 열에 있는 3개의 행들에서 최대 찾기
*/

int t, n, m;
int dp[21][21];
int arr[21][21];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> t;
	for (int test = 0; test < t; test++) {
		cin >> n >> m;
		for (int i = 0; i < 21; i++) {
			for (int j = 0; j < 21; j++) {
				dp[i][j] = 0;
				arr[i][j] = 0;
			}
		}
		
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				cin >> arr[i][j];
			}
		}

		for (int j = 1; j <= m; j++) {
			for(int i=1;i<=n;i++) 
				dp[i][j] = max(dp[i - 1][j - 1], max(dp[i][j - 1], dp[i + 1][j - 1])) + arr[i][j];
		}
		
		/*for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				cout << dp[i][j] << ' ';
			}
			cout << endl;
		}*/

		int answer = 0;
		for (int i = 1; i <= n; i++) {
			answer = max(answer, dp[i][m]);
		}
		cout << answer << '\n';
	}

	return 0;
}
