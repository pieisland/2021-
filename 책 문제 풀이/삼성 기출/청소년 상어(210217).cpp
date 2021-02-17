#include<cstdio>
#include<stdio.h>
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>

using namespace std;

/*
망할 청소년 상어....
아니 이 문제때문에 진짜 어제부터 오늘 아침까지 시간만 낭비했다.
ㅋㅋㅋ 안나왔던 이유가 dir 에서 y, x 넣는데 x, y 넣어서 이상한 방향 나와서였다는게...
진짜 열불이 남.

아무튼간에 이 문제에서 배울 점은.
1. 배열을 언제 복사해야하는지를 아는 것.
- dfs로 배열을 바꾸면서 다음 단계로 넘어가는 경우게 다른 경우의 수들에 문제가 없도록
전역변수 배열을 바꾸는 게 아니라 복사해서 바꾸어나가야 한다.
2. 배열을 매개변수로 넘기는 방법
- 함수 호출하는 데서는 이름만 넘기면 되고, 함수 정의에서는 다 표시해줘도 된다.
2차원 배열할 때는 두번째만 제대로 표시해줘도 됐던 걸로 안다.
3. 숫자와 방향 정보를 표시하기 위해서 3차원 배열로 하며 [][][2] 로 저장하는 점.
4. 방향 회전하기.
- 복잡하게 하지 말고 for문으로 돌린다..

어려운 문제였고 시간낭비해서 어이 없는 문제였다.. ^0^
그래도 이래저래... 뭐..
*/

int dir[8][2] = { {-1,0}, {-1,-1}, {0, -1}, {1, -1}, {1, 0}, {1, 1}, {0, 1}, {-1, 1} };
int ans;

bool isinside(int y, int x) {
	if (y >= 0 && y < 4 && x >= 0 && x < 4) return true;
	return false;
}

void moveFish(int arr[4][4][2], int sharky, int sharkx) {

	/*for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			cout << arr[i][j][0] << '(' << arr[i][j][1] << ')' << ' ';
		}
		cout << endl;
	}*/

	for (int num = 1; num <= 16; num++) {
		int posy = -1, posx = -1;
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				if (num == arr[i][j][0]) {
					//찾는 물고기
					posy = i;
					posx = j;
					break;
				}
			}
			//찾았으면 그냥 더이상 찾지 말라구요.
			if (posy != -1 && posx != -1) break;
		}

		//그 물고기가 없다면
		if (posy == -1 && posx == -1) {
			continue;//그냥 넘어간다.
		}
		//cout <<"num: "<< num << ' ' << "posy: "<<posy << ' ' <<"posx: "<< posx << endl;

		int fishDir = arr[posy][posx][1];
		//cout << "dir: " << fishDir << endl;

		for (int i = 0; i < 8; i++) {
			int ny = posy + dir[fishDir][0];
			int nx = posx + dir[fishDir][1];

			if (isinside(ny, nx)) {
				if (!(ny == sharky && nx == sharkx)) {
					int tmpNum, tmpDir;
					tmpNum = arr[ny][nx][0];
					tmpDir = arr[ny][nx][1];

					arr[ny][nx][0] = arr[posy][posx][0];
					arr[ny][nx][1] = fishDir;

					arr[posy][posx][0]= tmpNum;
					arr[posy][posx][1] = tmpDir;
					/*arr[posy][posx][1] = fishDir;
					int tmpNum, tmpDir;
					tmpNum = arr[posy][posx][0];
					tmpDir = arr[posy][posx][1];

					arr[posy][posx][0] = arr[ny][nx][0];
					arr[posy][posx][1] = arr[ny][nx][1];
					arr[ny][nx][0] = tmpNum;
					arr[ny][nx][1] = tmpDir;
					*/
					//cout << "new pos" << endl;
					//cout << "ny, nx: " << ny << ' ' << nx << ' ' << fishDir << endl;

					break;
				}
			}
			fishDir++;
			if (fishDir == 8) fishDir = 0;
		}

		//나는 이렇게 했었는데 그냥 for문으로 8번 돌리는 게 훨씬 깔끔한 것 같다.
		/*int rotCnt = 0;

		while (1) {
			int ny = posy + dir[fishDir][0];
			int nx = posx + dir[fishDir][1];

			//못가는 경우. 범위를 벗어나거나 상어의 위치일 때
			if (!isinside(ny, nx) || (ny == sharky && nx == sharkx))
			{
				fishDir++;
				if (fishDir == 8) fishDir = 0;

				//8번을 돌았다는건 다시 처음으로 돌아온 것이기 때문에 멈춘다.
				rotCnt++;
				if (rotCnt == 8) break;
			}
			else {
				if (arr[ny][nx][0] == -1) {
					//상어의 위치는 아닌데 먹힌 부분이라 비었다면
					arr[ny][nx][0] = arr[posy][posx][0];
					arr[ny][nx][1] = arr[posy][posx][1];
					//이제 옮겨갔으니까 얘는 그러면 없애줘야하는거지?
					arr[posy][posx][0] = -1;
					//방향정보는 굳이 참고는 안해도 될 것이고.
					//arr[posy][posx][1];
				}
				else {//다른 물고기 있음.
					//서로 옮겨야 된다.
					int tmpPos, tmpDir;
					tmpPos = arr[ny][nx][0];
					tmpDir = arr[ny][nx][1];

					arr[ny][nx][0] = arr[posy][posx][0];
					arr[ny][nx][1] = arr[posy][posx][1];
					arr[posy][posx][0] = tmpPos;
					arr[posy][posx][1] = tmpDir;
				}

				//바꿨으니 끝
				break;
			}
		}*/
	}


	/*for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			cout << arr[i][j][0] << '(' << arr[i][j][1] << ')' << ' ';
		}
		cout << endl;
	}*/
}

vector<pair<int, int>> getPossiblePositions(int arr[4][4][2], int y, int x) {
	vector<pair<int, int>> positions;
	int direction = arr[y][x][1];

	//어디 있든 별로 상관 안하고 그냥 네 번 가는걸로 보네요
	//어차피 isinside에서 걸릴거니까.. 힘들게 할 필요 없이.
	for (int i = 0; i < 4; i++) {
		y += dir[direction][0];
		x += dir[direction][1];

		if (isinside(y, x)) {
			if (arr[y][x][0] != -1) {
				//물고기가 있다면
				positions.push_back({ y, x });

				//cout << y << ' ' << x << endl;
			}
		}
	}

	return positions;
}

void dfs(int arr[4][4][2], int y, int x, int total) {
	//복사해서 안 넘기면 덮어써지면서 잘못된 결과가 나온다.
	int copyarr[4][4][2];
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			for (int k = 0; k < 2; k++) {
				copyarr[i][j][k] = arr[i][j][k];
			}
		}
	}

	//해당 위치에 있는 물고기 먹어요.
	total += copyarr[y][x][0];
	copyarr[y][x][0] = -1;//이제 먹었으니까..
	//넘어온 y, x가 결국 상어의 위치가 되는 거겠네요.

	moveFish(copyarr, y, x);

	vector<pair<int, int>> positions = getPossiblePositions(copyarr, y, x);
	if (positions.size() == 0) {
		//더이상 갈 곳이 없다면 갱신한다.
		ans = max(ans, total);
		return;
	}

	//이제 상어가 움직일 수 있는 곳에 다 움직여야 함.
	for (int i = 0; i < positions.size(); i++) {
		dfs(copyarr, positions[i].first, positions[i].second, total);
	}
}

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int arr[4][4][2];//3차원 배열로 해당 위치의 물고기 번호랑 방향 정보 저장한다.
	//방향 정보는 인덱스 맞추기 위해서 -1을 했다.

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			int fishnum;
			int direction;
			cin >> fishnum >> direction;
			arr[i][j][0] = fishnum;
			//편하게 하려고 1 뺴고 넣음.
			arr[i][j][1] = direction - 1;
		}
	}

	//상어가 이제 먹으러 갈거에요.
	dfs(arr, 0, 0, 0);

	cout << ans << '\n';

	return 0;
}
