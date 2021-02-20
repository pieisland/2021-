#include<cstdio>
#include<stdio.h>
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>

using namespace std;

/*
삼각형의 형태와 실제 배열 인덱스가 헷갈려서 한 번 쯤은 틀려주는 문제..
그리고 음수 처리때문에 1번부터 처리하는 게 좋다.

그게 무슨 말이냐 하면, dp[i-1][j]를 할 때 i-1이 음수가 될 수 있다는 거다.
인덱스가 음수가 되면 에러가 발생하니까(런타임 에러)
따로 신경 안 쓰기 위해서 1로 하면 어차피 인덱스가 0이 되고 0이 들어있기 때문에 영향을 주지 않는다.

하지만 만약 이 문제가 정수 삼각형에 음수 값이 들어갈 수 있는 문제라면 잘못된 결과가 초래될 수 있다.
그래서 아마 그때는 가장 작은 수를 넣어줘야 하지 않을까 싶다.
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
