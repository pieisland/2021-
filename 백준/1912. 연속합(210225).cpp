#include<cstdio>
#include<stdio.h>
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>
#include<cmath>

using namespace std;

int n;
int arr[100000];
int dp[100000];

//n개의 정수로 이루어진 임의의 수열이 주어지는데 연속된 몇 개의 수를 선택해 구할 수 있는 합 중 가장 큰 합 구하기.
//수는 한 개 이상 선택해야한다.

//순간, 나를 포함을 안해도 되는 거 아닌가? 라고 생각해는데
//그거는 어차피 dp[i-1]에 있는거고
//i번째를 선택했을 때의 최대값이라고 생각하면 되겠지..?

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];

	dp[0] = arr[0];
	for (int i = 1; i < n; i++) {
		dp[i] = max(dp[i - 1] + arr[i], arr[i]);
	}

	int ans = dp[0];
	for (int i = 1; i < n; i++) ans = max(dp[i], ans);

	cout << ans;

	return 0;
}
