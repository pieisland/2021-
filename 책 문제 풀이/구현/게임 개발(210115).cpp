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
설명이 별로 안 자세한 것 같음.
바다든 육지든 못가면 돌기만 하는 걸로 생각하고 풀었다. 명확히 안나와있네.

북 동 서 남 서를 0 1 2 3 인덱스로 주는데
도는 거는 왼쪽으로 돌라해서, 초기에 방향을 ++ 했다가 잘못 돌아서 이상하게 나왔음.
뒤로 가는 것도 있고 가도 왼쪽으로 가는 게 있으니까 더 헷갈린다. 

answer가 기본 1인 이유는 맨 처음에 육지에서 출발하기 때문.
*/

int n, m;

int board[50][50];
int check[50][50];
int dir[4][2] = { {0, -1}, {-1, 0}, {0, 1}, {1, 0} };//이거는 북 동 남 서 가 0 1 2 3 이라 왼쪽으로 돌 때는 인덱스 마이너스 해야됨.
int back[4][2] = { {1, 0}, {0, -1}, {-1, 0}, {0, 1} };//북 동 남 서가 뒤로 갈 때

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;

	int y,x,pos;
	cin >> y >> x >> pos;
	check[y][x] = 1;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
		}
	}

	int cy = y;
	int cx = x;
	int cpos = pos;
	int ans = 1;

	int cnt = 0;
	while (1) {
		//왼쪽을 본다
		int ny = cy + dir[cpos][0];
		int nx = cx + dir[cpos][1];

		if (check[ny][nx] == 0 && board[ny][nx] == 0) {
			//안가봤고 육지라면
			check[ny][nx] = 1;//가봤다.
			ans++;
			cy = ny;
			cx = nx;
			cpos--;
			if (cpos <0) cpos = 3;
			cnt = 0;
		}
		else if (check[ny][nx] == 1 || board[ny][nx]==1) {
			//못가는 데라면 돌기만 한다.
			cpos--;
			if (cpos <0) cpos = 3;
			cnt++;
		}
	
		if (cnt == 4) {
			ny = cy + back[cpos][0];
			nx = cx + back[cpos][1];
			if (board[ny][nx] == 1) {
				break;
			}
			else {
				cy = ny;
				cx = nx;
				cnt=0;
			}
		}
	}

	cout << ans << '\n';

	return 0;
}

/*
2차 풀이 210218
저번에 더 복잡하게 풀어버린 듯.

#include<cstdio>
#include<stdio.h>
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>
#include<cmath>

using namespace std;

//바다는 1, 육지는 0
int board[50][50];
int n, m;
int charx, chary, d;
int dir[4][2] = { {-1, 0}, {0, -1}, {1, 0}, {0,1} };
int check[50][50];

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	cin >> chary >> charx >> d;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
		}
	}
	
	int cy = chary;
	int cx = charx;
	int cd = d;
	check[cy][cx] = 1; //가본 칸 표시

	int ans = 1;
	int count = 0;
	while (1) {
		int nd = (cd + 1) % 4;
		int ny = cy + dir[nd][0];
		int nx = cx + dir[nd][1];

		if (board[ny][nx] == 0 && check[ny][nx] == 0) {
			//육지이며 아직 가보지 않은 곳이라면
			cd = nd;
			check[ny][nx] = 1;
			cy = ny;
			cx = nx;
			count = 0;
			ans++;
		}
		else { //어쨌든 못간다는건데
			
			count++;

			if (count == 4) {
				//다 돌았으면 바라보는 방향을 유지하라 해서 아직 안 돌림
				ny = cy - dir[cd][0];
				nx = cx - dir[cd][1];

				//한 칸 뒤로 갔는데 바다면 멈춘다.
				if (board[ny][nx] == 1)
				{
					break;
				}
			}
			else {
				cd = nd;
			}
		}
	}

	cout << ans << '\n';

	return 0;
}
*/
