#include<cstdio>
#include<stdio.h>
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>

using namespace std;

int n;
int board[20][20];
int sy, sx; //shark y, x
int ssize = 2; //기본 크기가 2다.
int eatCnt; //몇 마리의 물고기를 먹었는가
int ans; //도움 요청 없이 물고기 잡아먹을 수 있는 시간

int dir[4][2] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };

bool isInside(int y, int x) {
	if (y >= 0 && y < n && x >= 0 && x < n) return true;
	else return false;
}

int getDist(int y, int x) {

	int check[20][20] = { 0 };
	check[sy][sx] = 1;

	queue<pair<int, int>> q;
	q.push({ sy, sx });

	while (!q.empty()) {
		int cy = q.front().first;
		int cx = q.front().second;
		q.pop();

		if (cy == y && cx == x) {
			return check[cy][cx] - 1;
		}

		for (int i = 0; i < 4; i++) {
			int ny = cy + dir[i][0];
			int nx = cx + dir[i][1];

			if (isInside(ny, nx) && check[ny][nx] == 0 && board[ny][nx] <= ssize) {
				q.push({ ny, nx });
				check[ny][nx] = check[cy][cx] + 1;
			}
		}
	}

	return -1;
}

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];

			if (board[i][j] == 9) {
				sy = i;
				sx = j;

				board[i][j] = 0;
			}
		}
	}

	while (1) {
		int minDist = 100000000;
		int py = -1;
		int px = -1;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				//먹을 수 있는 물고기
				if (0 < board[i][j] && board[i][j] < ssize) {
					int dist = getDist(i, j);

					if (dist == -1)  continue;

					if (dist < minDist) {
						minDist = dist;
						py = i;
						px = j;
					}
					else if (dist == minDist) {
						if (i < py) {
							py = i;
							px = j;
						}
						else if (i == py) {
							if (j < px) {
								py = i;
								px = j;
							}
						}
					}
				}
			}
		}

		if (py == -1 && px == -1) {
			break;
		}

		board[py][px] = 0;
		sy = py;
		sx = px;
		eatCnt += 1;
		if (ssize == eatCnt) {
			ssize += 1;
			eatCnt = 0;
		}
		ans += minDist;
	}

	cout << ans << '\n';

    return 0;
}
