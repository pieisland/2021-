#include<cstdio>
#include<stdio.h>
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>
#include<cmath>

using namespace std;

int n, m;
int number[100001];
int dp[100001];

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> number[i];
	dp[1] = number[1];
	for (int i = 2; i <= n; i++) {
		dp[i] = dp[i - 1] + number[i];
	}
	
	cin >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		cout << dp[b] - dp[a - 1] << '\n';
	}
	
	return 0;
}
