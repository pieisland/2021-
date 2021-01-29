#include<cstdio>
#include<stdio.h>
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>

using namespace std;

/*
bfs 하면서 국경 문을 열고, 가능한 모든 문을 다 연 후에
바로 처리해주는 방식으로 하니 시간초과가 해결됐다.
이전에 했던 방식인, 일단 다 개방해두고 다시 같은 것끼리 찾는 과정이
시간 많이 드는 듯 하다. 3중 포문을 돌리니 그럴만도...

할 때 바로 벡터에 넣어 처리하기..

옛날에 풀었던 풀이를 봤는데
dfs로 하니까 시간이 확 줄던데.
이런 문제는 bfs보다는 dfs가 적절한 걸까?
아니면 단순 구현방식의 차이일까.
*/

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

	vector<pair<int, int>> vec;
	vec.push_back({ y, x });
	int sumVal = 0;

	while (!q.empty())
	{
		int cy = q.front().first;
		int cx = q.front().second;
		sumVal += board[cy][cx];
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
					vec.push_back({ ny, nx });
				}
			}
		}
	}

	for (int i = 0; i < vec.size(); i++) {
		int y = vec[i].first;
		int x = vec[i].second;

		board[y][x] = sumVal / vec.size();
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
	
		answer++;
	}

	cout << answer << '\n';

	return 0;
}
