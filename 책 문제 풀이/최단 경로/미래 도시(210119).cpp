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
거리가 다 1이라서.. 의아했었다.
일반적으로 거리가 다 다른 걸 주는데..

플로이드 와샬 문제를 풀 때 주의할 점은
초기에 최대 값을 넣어줘야 한다는 점이다.

최단 경로를 찾는 것이기 때문에, 경로가 없는 값에 0이 들어가있으면
제대로 된 결과가 나오지 않는다. 왜냐면 그게 최단 경로가 되어버리므로.
조심하길 바라고.

마지막에 INF보다 큰지를 확인했는데, INF 값을 두 번 더해도 int형 범위를 넘어가지 않기 때문에
범위를 신경쓰지 않아도 됐다.

초반에 ==INF 로 해서 틀렸었음..
*/

int n, m;
int connect[101][101];
int x, k;
int INF = 987654321;

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);


	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			connect[i][j] = INF;
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
	if (ans >= INF) ans = -1;
	cout << ans << '\n';

	return 0;
}
