#include<cstdio>
#include<stdio.h>
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>

using namespace std;

/*
일반적인 문제랑 조금 달라서 헤맸다.
이 문제에서 중요한 건 서로 다른 종류의 바이러스가 있고 해당 바이러스들이
같은 시간에 퍼지기는 하는데 우선순위가 있다는 것이다.
숫자가 작은 게 먼저 퍼져야 한다.

그렇게 하기 위해서..
queue에 모든 바이러스들을 넣은 채로 시작을 해야하는데
바이러스 크기에 맞게 숫자가 작은 바이러스들을 먼저 넣어주어 먼저 실행될 수 있도록 했다.
모든 바이러스를 큐에 넣고 그 때야 bfs를 실행하면 된다.

그리고 특정 시간의 결과를 보고 싶기 때문에 시간에 대한 처리를 해줘야 하는데
나는 check의 값을 통해 처리해줬다.
check 값이 원래 방문을 했는지 여부를 판단하기위해 사용하기 때문에 1부터 시작해야 해서
원하는 시간이 됐는지 여부는 +1을 한 결과로 판단했다.
s+1가 맨 처음 나왔을 때 멈추면 더이상 바이러스가 퍼지지 않은 결과를 얻을 수 있다.

그렇게 좀 헤매면서 구했다.
*/

int n, k; //시험관 크기, 바이러스 종류
int s, y, x; //시간과 보고싶은 위치
int board[200][200];
int virus[10001]; //어떤 종류의 바이러스가 있는지 저장.
int check[200][200];
int dir[4][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
queue<pair<int, int>> q;

bool isInside(int y, int x) {
	if (y >= 0 && y < n && x >= 0 && x < n) return true;
	else return false;
}

void bfs() {
	while (!q.empty()) {
		int cy = q.front().first;
		int cx = q.front().second;
		int val = board[cy][cx];
		
		//처음을 1로 주기 때문에 +1을 해줘야 하고
		//이게 맨 처음에 나오는 순간에 바로 break를 하면 된다.
		if (check[cy][cx] == s + 1) {
			break;
		}

		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = cy + dir[i][0];
			int nx = cx + dir[i][1];
			if (isInside(ny, nx) && board[ny][nx] == 0 && check[ny][nx] == 0) {
				board[ny][nx] = val;
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

	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
			virus[board[i][j]] = 1;
		}
	}
	
	cin >> s >> y >> x;

	for (int v = 1; v < 1001; v++) {
		if (virus[v] == 0) continue;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (board[i][j] == v && check[i][j] == 0) {
					q.push({ i, j });
					check[i][j] = 1;
				}
			}
		}
	}

	bfs();

	/*for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << board[i][j] << ' ';
		}
		cout << endl;
	}*/

	cout << board[y - 1][x - 1] << '\n';

	return 0;
}
