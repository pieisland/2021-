#include<cstdio>
#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
#include<queue>
using namespace std;

int n, m;
int miro[200][200];
int check[200][200];
int dir[4][2] = { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };

bool isinside(int y, int x) {
	if(y >= 0 && y < n&& x >= 0 && x < m) return true;
	else return false;
}

int bfs(int y, int x) {
	queue<pair<int, int>> q;
	q.push({ y, x });
	check[y][x] = 1;

	while (!q.empty()) {
		int cy = q.front().first;
		int cx = q.front().second;
		q.pop();

		if (cy == n - 1 && cx == m - 1) {
			return check[cy][cx];
		}

		for (int i = 0; i < 4; i++) {
			int ny = cy + dir[i][0];
			int nx = cx + dir[i][1];

			if (isinside(ny, nx) && miro[ny][nx] == 1 && check[ny][nx] == 0)
			{
				check[ny][nx] = check[cy][cx] + 1;
				q.push({ ny, nx });
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%1d", &miro[i][j]);
		}
	}

	cout<<bfs(0, 0)<<'\n';

	return 0;
}
