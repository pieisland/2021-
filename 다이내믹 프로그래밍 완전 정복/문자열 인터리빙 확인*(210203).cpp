#include<cstdio>
#include<stdio.h>
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>

using namespace std;

/*
문자열 인터리빙 확인 문제.
세 개의 문자열이 주어졌을 때 앞의 두 문자열을 엮어서
세 번째 문자열을 만들 수 있는지 확인.
글자수 확인은 생략했다. 

헷갈리는 부분이.. 무조건 같은 값이라고 해서 true가 되는 게 아니라는 거다.
이전까지 다 true여야 true가 된다는 거.. 이전 결과를 봐야한다는 것.

나는 아직 이런 문제가 너무 어렵다.. 
*/

string a, b, c;
bool dp[101][101];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> a >> b >> c;
	int n = a.length();
	int m = b.length();

	dp[0][0] = true;
	for (int i = 1; i <= n; i++) {
		if (a[i - 1] != c[i - 1]) {
			dp[i][0] = false; //다르면 false
		}
		else {
			dp[i][0] = dp[i - 1][0]; //같으면 이전 값
		}
	}

	for (int i = 1; i <= m; i++) {
		if (b[i - 1] != c[i - 1]) {
			dp[0][i] = false;
		}
		else {
			dp[0][i] = dp[0][i - 1];
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (c[i + j - 1] == a[i - 1] && c[i + j - 1] != b[j - 1]) {
				//a랑만 같을 떄
				dp[i][j] = dp[i - 1][j];
			}
			else if (c[i + j - 1] != a[i - 1] && c[i + j - 1] == b[j - 1]) {
				//b랑만 같을 때
				dp[i][j] = dp[i][j - 1];
			}
			else if (c[i + j - 1] == a[i - 1] && c[i + j - 1] == b[j - 1]) {
				//둘 다 같으면 둘 중 하나라도 true면 가능
				dp[i][j] = dp[i-1][j] || dp[i][j - 1];
			}
			else {
				//둘 다 다르면 불가
				dp[i][j] = false;
			}
		}
	}

	cout << dp[n][m] << '\n';

	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= m; j++) {
			cout << dp[i][j] << ' ';
		}
		cout << '\n';
	}

	return 0;
}
