#include<cstdio>
#include<stdio.h>
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>

using namespace std;

/*
이 문제 진짜로 백준에서 풀었던 문제였는데...
ㅎㅎㅎ... 분명 봤던 문제였는데 아무 생각도 안남

핵심은 모두 비교할 수 있다면 a에서 b로 가던 b에서 a로 가던 경로가 있다는 거..
그걸 이해하고 기억해야한다....

마지막에 어처구니 없는 실수해서 시간 잡아먹은거는 화나네..
*/

int n, m;
int INF = 987654321;
int arr[501][501];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n >> m;
	for (int i = 1; i <= 500; i++) {
		for (int j = 1; j <= 500; j++) {
			arr[i][j] = INF;
			if (i == j) arr[i][j] = 0;
		}
	}

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		arr[a][b] = 1;
	}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);
			}
		}
	}

	int ans = 0;
	for (int i = 1; i <= n; i++) {
		int cnt = 0;
		for (int j = 1; j <= n; j++) {
			if (arr[i][j] != INF || arr[j][i] != INF) {
				cnt++;
			}
		}
		//cout << cnt << endl;
		if (cnt == n) ans++;
	}

	/*for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cout << arr[i][j] << ' ';
		}
		cout << endl;
	}*/

	cout << ans << '\n';

	return 0;
}
