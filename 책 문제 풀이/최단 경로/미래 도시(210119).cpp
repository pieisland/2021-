#include<cstdio>
#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
#include<queue>
using namespace std;

/*
플로이드 와샬 문제.
거리가 다 1이라서.. 좀..?
*/

int n, m;
int connect[101][101];
int x, k;

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);


	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			connect[i][j] = 987654321;
			if (i == j) connect[i][j] = 0;
		}
	}
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		connect[a][b] = 1;
		connect[b][a] = 1;
	}

	cin >> x >> k;

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				connect[i][j] = min(connect[i][j], connect[i][k] + connect[k][j]);
			}
		}
	}

	int ans = connect[1][k] + connect[k][x];
	//cout << connect[1][k] << ' ' << connect[k][x] << endl;
	if (ans >= 987654321) ans = -1;
	cout << ans << '\n';

	return 0;
}
