#include<cstdio>
#include<stdio.h>
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>

using namespace std;

/*
플로이드..
솔직히 왜 자기 자신으로 가는 걸 0으로 보는지는 모르겠지만.....
다른 거 거쳐서 올 수 있는거 아니냐고요.

그냥 전형적인 플로이드 문제였다.
마지막에 ==inf로 보는 이유는 inf보다 크게 나오지는 않기 때문이다.
근데 저번에 다른 문제 풀 때 inf 이상이면 이라고 본 게 있었는데..
걔는 무슨 차이점이 있었던거였던가..
*/

int n;
int m;
int arr[101][101];
int INF = 987654321;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n;
	cin >> m;

	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			arr[i][j] = INF;
		}
	}

	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;

		if (c < arr[a][b]) {
			arr[a][b] = c;
		}
	}
	
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (arr[i][j] > arr[i][k] + arr[k][j]) {
					arr[i][j] = arr[i][k] + arr[k][j];
				}
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (arr[i][j] == INF || i==j) {
				arr[i][j] = 0;
			}
			cout << arr[i][j] << ' ';
		}
		cout << endl;
	}

	return 0;
}
