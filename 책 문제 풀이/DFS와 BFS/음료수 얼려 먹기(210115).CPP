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
int arr[1000][1000];
int check[1000][1000];
int dir[4][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };

bool isinside(int y, int x) {
	if (y >= 0 && y < n && x >= 0 && x < m) return true;
	else return false;
}

void dfs(int y, int x) {

	for (int i = 0; i < 4; i++) {
		int ny = y + dir[i][0];
		int nx = x + dir[i][1];

		if(isinside(ny, nx) && arr[ny][nx]==0 && check[ny][nx]==0) {
			check[ny][nx] = 1;
			dfs(ny, nx);
		}
	}

	return;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%1d", &arr[i][j]);
		}
	}

	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == 0 && check[i][j]==0) {
				dfs(i, j);
				ans++;
			}
		}
	}

	cout << ans << '\n';

	return 0;
}

/*
210224
솔직히 나는 이런 문제는 bfs가 더 편하다.

#include<cstdio>
#include<stdio.h>
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>
#include<cmath>

using namespace std;

int n, m;
int board[1000][1000];
int check[1000][1000];
int ans;
int dir[4][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };

bool isinside(int y, int x) {
	if (y >= 0 && y < n && x >= 0 && x < m) return true;
	return false;
}

void bfs(int y, int x) {
	check[y][x] = 1;
	queue<pair<int, int>> q;
	q.push({ y, x });

	while (!q.empty()) {
		int cy = q.front().first;
		int cx = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = cy + dir[i][0];
			int nx = cx + dir[i][1];

			if (isinside(ny, nx) && check[ny][nx] == 0 && board[ny][nx] == 0) {
				check[ny][nx] = 1;
				q.push({ ny, nx });
			}
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%1d", &board[i][j]);
			//cin >> board[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (board[i][j] == 0&& check[i][j] == 0) {
				bfs(i, j);
				ans++;
			}
		}
	}

	cout << ans;

	return 0;
}
*/
