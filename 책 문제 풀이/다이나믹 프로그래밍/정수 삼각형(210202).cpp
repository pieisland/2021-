#include<cstdio>
#include<stdio.h>
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>

using namespace std;

/*
삼각형의 형태와 실제 배열 인덴스가 헷갈려서 한 번 쯤은 틀려주는 문제..
그리고 음수 처리때문에 1번부터 처리하는 게 좋다.
*/

int n;
int tri[501][501];
int dp[501][501];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			cin >> tri[i][j];
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			dp[i][j] = max(dp[i - 1][j-1], dp[i - 1][j]) + tri[i][j];
		}
	}

	/*for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			cout << dp[i][j] << ' ';
		}
		cout << endl;
	}*/

	int answer = 0;
	for (int i = 1; i <= n; i++) {
		answer = max(answer, dp[n][i]);
	}

	cout << answer << '\n';


	return 0;
}
