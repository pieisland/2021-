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
LCS 문제(Longest Common Subsequence)
최소 교정 비용 문제랑 뭔가 비슷한 감이 살짝 있기는 하지만 다르다.
애는 길이를 구하는 것이라서
같으면 길이가 1 증가하고,
다르면, 이전까지 구한 거에서 찾는 것.
최소 비용에서는 같으면 왼쪽 위 값 가지고
다르면 삽입 삭제 치환에서 1을 더하는 식이었지......
^0^.....
*/

string s1, s2;
int dp[31][31];

/*
테스 케이스)
AAACCGTGAGTTATTCGTTCTAGAA
CACCCCTAAGGTACCTTTGGTTC
14

ABCD
AEBD
3
*/

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> s1 >> s2;
	int n = s1.length();
	int m = s2.length();

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (s1[i-1] == s2[j-1]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else {
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}

	cout << dp[n][m];

	return 0;
}
