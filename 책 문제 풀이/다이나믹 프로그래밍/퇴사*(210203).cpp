#include<cstdio>
#include<stdio.h>
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>

using namespace std;

int n;
int t[16];
int p[16];
int dp[16];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> t[i] >> p[i];
		//일단 모든 날에 일한다고 생각한다.
		dp[i] = p[i];
	}

	for (int i = 2; i <= n; i++) {
		for (int j = 1; j < i; j++) {
			//이전 날에서 일을하고 다음 일할 날이 해당 날 이하라면
			if (j + t[j] <= i) {
				//... p[i]를 더하는게 안익숙하네요. 일반적으로 그 날에 일하는 거를 더하는데...
				//그래서 p[j]했다가 후드려맞고 왔다. 이미 위에서 일하는 걸 가정하고 넣어서이기 때문인 것 같다.
				//이전날에 일 안하고 오늘 일하는거 vs 이전날에 일하고 오늘도 일하는거
				dp[i] = max(dp[i], dp[j] + p[i]);
			}
		}
	}

	int answer = 0;
	for (int i = 1; i <= n; i++) {
		//해당 날에 일했을 때 퇴사일 이전이라면
		if (i + t[i] - 1 <= n) {
			answer = max(answer, dp[i]);
		}
	}

	cout << answer << endl;

	return 0;
}
