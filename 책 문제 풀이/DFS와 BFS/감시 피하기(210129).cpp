#include<cstdio>
#include<stdio.h>
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>

using namespace std;

/*
감시 라는 문제에서 변형된 버전인가?
어렵지는 않았는데 while문에서 return하게 짠 게 좀 마음에 안 들었다..
벽의 위치와 선생의 위치를 모두 담아두고
벽을 세운 뒤 모든 선생에 대해서 동서남북 방향으로 다 본다.
벽이 있으면 멈추고, 학생이 보이면 바로 false를 보낸다.
*/

int n;
char board[6][6];
vector<int> sel;
vector<pair<int, int>> vec;
vector<pair<int, int>> teacher;
int dir[4][2] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };
string answer ="NO";

void makeWall() {
	for (int i = 0; i < 3; i++) {
		int idx = sel[i];
		int y = vec[idx].first;
		int x = vec[idx].second;
		board[y][x] = 'O';
	}
}

void breakWall() {
	for (int i = 0; i < 3; i++) {
		int idx = sel[i];
		int y = vec[idx].first;
		int x = vec[idx].second;
		board[y][x] = 'X';
	}
}

bool isinside(int y, int x) {
	if (y >= 0 && y < n && x >= 0 && x < n) return true;
	else return false;
}

bool checkWatching() {
	for (int i = 0; i < teacher.size(); i++) {
		int y = teacher[i].first;
		int x = teacher[i].second;

		//bool possible = true;
		for (int j = 0; j < 4; j++) {
			int dy = dir[j][0];
			int dx = dir[j][1];

			int ny = y + dy;
			int nx = x + dx;
			while (isinside(ny, nx)) {
				if (board[ny][nx] == 'S') {
					//answer = "NO";
					return false;
					
					//possible = false;
					//break;
				}

				if (board[ny][nx] == 'O') {
					//벽이라면
					break;
				}
				ny = ny + dy;
				nx = nx + dx;
			}
			//if (!possible) break;
		}
	}

	return true;
}

void dfs(int start, int cnt) {
	if (cnt == 3) {
		/*for (int i = 0; i < 3; i++) {
			cout << sel[i] << ' ';
		}
		cout << endl;
		*/
		makeWall();

		bool val = checkWatching();
		if (val) {
			/*for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					cout << board[i][j] << ' ';
				}
				cout << endl;
			}
			cout << endl;*/

			answer = "YES";
		}

		breakWall();

		return;
	}

	if (start >= vec.size()) {
		return;
	}
		
	for (int i = start; i < vec.size(); i++) {
		sel.push_back(i);
		dfs(i + 1, cnt + 1);
		sel.pop_back();
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
			if (board[i][j] == 'X') {
				//벽을 설치할 수 있는 곳 저장
				vec.push_back({ i, j });
			}
			if (board[i][j] == 'T') {
				teacher.push_back({ i, j });
			}
		}
	}

	dfs(0, 0);
	cout << answer << '\n';

	return 0;
}
