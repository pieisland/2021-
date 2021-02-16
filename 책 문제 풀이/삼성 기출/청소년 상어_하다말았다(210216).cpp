#include<cstdio>
#include<stdio.h>
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>

using namespace std;

int n;
//방향은 1 빼야겠음..
//반시계 회전.
int dir[8][2] = { {-1,0}, {-1,-1}, {0, -1}, {1, -1}, {1, 0}, {1, 1}, {0, 1}, {-1, 1} };
int sea[4][4];
int fish[16+1];//물고기의 방향을 저장한다?
int ans;
int sy;
int sx;
int sharkDir;

bool isinside(int y, int x) {
	if (y >= 0 && y < 4 && x >= 0 && x < 4) return true;
	return false;
}

void moveFish() {
	for (int i = 1; i <= 16; i++) {
		//1번 물고기부터 해야되니까 저기 저장한거에서 또 찾아야되는..?
		//그런 이상한 형태가 되어버린다.
		int y=-1, x=-1;
		for (int a = 0; a < 4; a++) {
			for (int b = 0; b < 4; b++) {
				if (sea[a][b] == i) {
					//해당 물고기라면
					y = a, x = b;
				}
			}
		}

		if (y == -1 && x == -1) {
			//이미 잡아먹힌 물고기
			continue;
		}

		int fishDir = fish[sea[y][x]];
		int rotCnt = 0;//회전 횟수를 센다.
		while (1) {
			int ny = y + dir[fishDir][0];
			int nx = x + dir[fishDir][1];

			//범위를 넘거나 상어가 있는 위치다.
			if (!isinside(ny, nx) || (ny == sy && nx == sx))
			{
				//못 갑니다.	
				fishDir++;
				if (fishDir == 8) fishDir = 0;
				rotCnt++;
				if (rotCnt == 8) break;
			}
			else {
				//갈 수 있습니다.
				if (sea[ny][nx] == 0) {
					//빈 칸이면 그냥 이동하면 되고
					
					//물고기 번호 이동
					sea[ny][nx] = sea[y][x];
					fish[sea[ny][nx]] = fishDir;
				}
				else {
					//원래 거기 있던 물고기랑 자리 바꾸기 하면 됨.
					int tmp = sea[y][x];
					sea[y][x] = sea[ny][nx];
					sea[ny][nx] = tmp;
					fish[sea[ny][nx]] = fishDir;
				}

				//바꾸면 끝이죠
				break;
			}
		}
	}
}

void dfs(int nowy, int nowx, int total) {
	total += sea[nowy][nowx];

}

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	//하지만 사실 이게 뭐.. 변화가 있다고 해도;
	//그래서 물고기 번호 합의 최댓값은 어떻게 구하는지는 모르겠음
	//dfs를 할 수도 없고
	//뭐 그리디가 답인건지도 모르겠고요.
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			int num, d;
			cin >> num >> d;
			fish[num] = d-1; //방향 저장
			sea[i][j] = num; //물고기 번호 저장
		}
	}

	//dfs(0, 0, 0);

	ans = sea[0][0];//맨 처음 칸의 물고기를 먹음
	sharkDir = fish[sea[0][0]];
	sy = 0, sx = 0;//상어의 위치 초기화하기
	sea[0][0] = 0;

	moveFish();

    return 0;
}
