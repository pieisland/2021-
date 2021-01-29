#include<cstdio>
#include<stdio.h>
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>

using namespace std;

int n;
int board[50][50];
int check[50][50];
int l, r;
int dir[4][2] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };

bool isinside(int y, int x) {
	if (y >= 0 && y < n && x >= 0 && x < n) return true;
	else return false;
}

void bfs(int y, int x, int val) {
	queue<pair<int, int>> q;
	check[y][x] = val;
	q.push({ y, x });

	while (!q.empty())
	{
		int cy = q.front().first;
		int cx = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = cy + dir[i][0];
			int nx = cx + dir[i][1];

			if (isinside(ny, nx) && check[ny][nx] == 0) {
				int diff = board[cy][cx] - board[ny][nx];
				if (diff < 0) diff = -diff;
				if (l <= diff && diff <= r) {
					check[ny][nx] = val;
					q.push({ ny, nx });
				}
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> l >> r;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
		}
	}

	int answer = 0;
	while (1) {

		int cnt = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				check[i][j] = 0;
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (check[i][j] == 0) {
					cnt++;
					bfs(i, j, cnt); 
				}
			}
		}
		//더이상 바뀔 국가가 없음.
		if (cnt == n * n) break;

		for (int val = 1; val<= cnt; val++) {
			//cnt가 동일한 국가끼리...
			vector<pair<int, int>> vec;
			int sumval = 0;
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					if (check[i][j] == val) {
						sumval += board[i][j];
						vec.push_back({ i, j });
					}
				}
			}
			int newval = sumval / vec.size();
			for (int i = 0; i < vec.size(); i++) {
				int y = vec[i].first;
				int x = vec[i].second;
				board[y][x] = newval;
			}
		}
		answer++;
	}

	cout << answer << '\n';

	return 0;
}
