#include<cstdio>
#include<stdio.h>
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>

using namespace std;

/*
분명 콘솔로 확인할 때는 2초가 넘는데....
시간 초과 안되고 정답이랜다.

이 문제는 bfs, dfs 다 하는 문제.
어렵다기 보다는 구현할 게 많은 문제.

그리고 이번에 함수 단위로 많이 쪼갰는데,
함수 위치 맞춰서 안 놓아서 함수 못찾고 그랬다.
어떤 함수에서 다른 함수를 사용하려고 할 때
그 함수는 미리 선언이 되어 있어야 한다는 거..
맨 위에 이름 다 적어두고 쓰는 게 아니라면 말이다.
오랜만에 다시 한 번 짚고 간다.
*/

int n, m;
int board[8][8];
int tmpBoard[8][8];
int check[8][8];
int dir[4][2] = { {0, 1}, {1, 0}, {-1,0}, {0,-1} };
vector<pair<int, int>> blank;
vector<int> idx;
int ans;

bool isinside(int y, int x) {
	if (y >= 0 && y < n && x >= 0 && x < m) return true;
	else return false;
}

void copyBoard() {
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			tmpBoard[i][j] = board[i][j];
		}
	}
}

void initCheck() {
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			check[i][j] = 0;
		}
	}
}

int getSafeArea() {
	int ret = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
		{
			if (tmpBoard[i][j] == 0) {
				ret++;
			}
		}
	}

	return ret;
}

void bfs(int y, int x) {
	queue<pair<int, int>> q;
	q.push({ y, x });

	check[y][x] = 1;
	while (!q.empty()) {
		int cy = q.front().first;
		int cx = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = cy + dir[i][0];
			int nx = cx + dir[i][1];

			if (isinside(ny, nx) && tmpBoard[ny][nx] == 0 && check[ny][nx] == 0) {
				check[ny][nx] = 1;
				tmpBoard[ny][nx] = 2;
				q.push({ ny, nx });
			}
		}
	}
}


void spreadVirus() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (check[i][j] == 0 && tmpBoard[i][j] == 2) {
				bfs(i, j);
			}
		}
	}

	int area = getSafeArea();
	ans = max(area, ans);
}

void makeWall() {
	copyBoard();
	initCheck();

	//벽을 세워준다..
	for (int i = 0; i < 3; i++) {
		int y = blank[idx[i]].first;
		int x = blank[idx[i]].second;

		tmpBoard[y][x] = 1;
	}
	
	spreadVirus();
}

void dfs(int start, int cnt, int max) {
	if (cnt == max) {
		makeWall();

		return;
	}

	if (start >= blank.size()) { return; }

	for (int i = start; i < blank.size(); i++) {
		idx.push_back(i);
		dfs(i + 1, cnt + 1, max);
		idx.pop_back();
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];

			if (board[i][j] == 0) {
				blank.push_back({ i, j });
			}
		}
	}
	
	dfs(0, 0, 3);
	cout << ans << '\n';

	return 0;
}
