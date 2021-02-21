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
큰 거를 찾아간다는 게 솔직히 이해가 팍 되지는 않는다만.
아마도 순서대로 찾기 위함일 것이다.

같을 때 왼쪽 위 대각선으로 가는 이유는
dp 테이블을 구성할 때 같은 경우 위쪽 대각선에서 왔기 때문. 
*/

string s1, s2;
int dp[31][31];

/*
테스트 케이스)
AAACCGTGAGTTATTCGTTCTAGAA
CACCCCTAAGGTACCTTTGGTTC
답: ACCTAGTATTGTTC

ABCD
AEBD
답: ABD
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

	int lcsLen = dp[n][m];

	vector<char> lcsValue;
	
	int i = n;
	int j = m;

	while (i > 0 && j > 0) {
		if (s1[i-1] == s2[j-1]) { //같은 문자라면 넣어준다.
			lcsValue.push_back(s1[i - 1]);
			//대각선으로 이동한다.
			i--;
			j--;
		}
		else { //다른 문자라면 더 큰 값을 찾아 이동한다.
			if (dp[i - 1][j] > dp[i][j - 1]) {
				i--;
			}
			else {
				j--;
			}
		}
	}

	//뒤에서부터 넣었기 때문에 뒤에서부터 출력한다.
	for (int i = 0; i < lcsLen; i++) {
		cout << lcsValue[lcsLen - 1 - i];
	}

	return 0;
}
