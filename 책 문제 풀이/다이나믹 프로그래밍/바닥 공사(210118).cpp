#include<cstdio>
#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
#include<queue>
using namespace std;

int n;
int dp[1001];

/*
유명한 n 타일 문제. 하지만 보기 싫은 문제.
그림을 그리면서 풀면 그나마 낫다.
곱하기를 해야하나 더하기를 해야하나 살짝 헷갈렸다.
*/

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	dp[1] = 1;
	dp[2] = 3;

	for (int i = 3; i <= n; i++) {
		dp[i] = dp[i - 1] + dp[i - 2] * 2;
		dp[i] = dp[i] % 796796;
	}

	cout << dp[n] << '\n';

	return 0;
}
