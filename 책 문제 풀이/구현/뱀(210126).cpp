#include<cstdio>
#include<stdio.h>
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>

using namespace std;

/*
다른 건 그렇다치고 뱀이 움직이는데
뱀 꼬리부분을 지워야하는데 어떻게 지워야하는지가
제일 생각이 안 났던 것 같다...

해결책은 큐를 사용하는 것이다.
큐는 선입 선출이기 때문에 먼저 들어간 게 먼저 나온다.
맨 처음에 (1,1)을 넣고 다음 방향으로 움직였다고 생각하면
(1, 1)을 빼야 하는데 큐의 front 값을 빼면 된다.
다음으로 움직인 위치가 새로 들어가게 되고
몸 길이가 늘어나든 상관없이 쉽게 꼬리 처리를 할 수 있다.
나는 뭐, 값 저장해두고 돌면서 1씩 증가하고 해야되나 했는데
그렇게 보니까 엄청 복잡한거임.. 말도 안되고. 직선은 또 어떻게 처리를 할거며..
큐가 이런 곳에서도 쓰일 수 있구나 싶었다.

꼬리가 있던 위치를 빼고 나면 board를 0으로 초기화해주는데
그렇게 쉽게 해줘도 되는 이유는 어차피 맵에는
사과에 대한 정보가 1이고 뱀에 대한 정보가 2 뿐이다.
아무것도 없으면 0일거고
뱀이 지나간 위치에서 다시 사과가 생길 일이 없기 때문에
그리고 다녀갔던 길에 꼬리가 있는 것이기 때문에
쉽게 0으로 초기화 해주면 되는 것이다.
굳이 뱀과 board에 대해 따로따로 배열을 만들어 줄 이유가 없다.

*/

int n;
int l, k;
int board[101][101];
//0일 때 오른쪽으로 가는 거고, +1이 되면 오른쪽 회전 -1이 되면 왼쪽 회전.
int dir[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
//회전 정보를 시간순으로 입력 받았기 때문에
//앞에서부터 빼서 볼 수 있는 큐 사용.
queue<pair<int, char>> rotInfo;
//큐를 사용하는 이유는 꼬리를 쉽게 뺴기 위함이다.
//새로 가는 곳은 뒤에 추가..
queue<pair<int, int>> snake;

bool isinside(int y, int x) {
	if (y >= 1 && y <= n && x >= 1 && x <= n) return true;
	else return false;
}

int main() {

	cin >> n;
	cin >> k;
	for (int i = 0; i < k; i++) {
		int y, x;
		cin >> y >> x;
		board[y][x] = 1;//사과
	}
	cin >> l;

	for (int i = 0; i < l; i++) {
		int x;
		char c;
		cin >> x >> c;
		//c가 L이면 왼쪽, D면 오른쪽
		
		//방향 전환을 하는 시간과 방향.
		rotInfo.push({ x, c });
	}

	int time = 0;
	int cy = 1, cx = 1;
	int d = 0;
	//뱀이 있는 곳은 2로 해준다.
	board[cy][cx] = 2;
	snake.push({ cy, cx });

	while (1) {
		time++;
		int ny = cy + dir[d][0];
		int nx = cx + dir[d][1];

		//벽에 부딪친 경우.
		if (!isinside(ny, nx)) {
			break;
		}

		//몸에 부딪친 경우
		//고전적인 뱀게임이라고 생각하면 안된다. 이 문제는 머리 먼저 늘어나고나서 확인 후에 줄어든다.
		if (board[ny][nx] == 2) {
			break;
		}

		//사과가 있는 경우. 몸 길이가 늘어난다.
		if (board[ny][nx] == 1) {
			snake.push({ ny, nx });
			board[ny][nx] = 2;
		}
		else { //그냥 일반적으로 가는 경우
			snake.push({ ny, nx }); //머리부분 위치 추가
			board[ny][nx] = 2;
			//꼬리 빼기
			int ty = snake.front().first;
			int tx = snake.front().second;
			board[ty][tx] = 0;
			snake.pop();
		}
		
		cy = ny;
		cx = nx;
		//비어있으면 안본다.
		if (rotInfo.empty()) continue;
		if (time == rotInfo.front().first) {
			//회전할 시간이 되었으면
			if (rotInfo.front().second == 'L') { //왼쪽 회전
				d--;
				if (d < 0) d = 3;
			}
			else { //오른쪽회전
				d++;
				if (d >= 4) d = 0;
			}
			rotInfo.pop();
		}
	}

	cout << time << '\n';

	return 0;
}

/*
210228
아 진짜 다시 풀었는데 또 동일한 데서 뱅뱅 돌고 있었따.
queue 안쓰고 vector를 썼었는데 그러면 꼬리 부분을 어떻게 지우지?
하고 있었음..
큐로 하면 새로운 위치가 뒤로 들어갈거고
이전에 위치는 앞에 있어서 꺼낼 수 있는거다.
이전에 머리였다고 해도 몸통이 되는거라서. 헷갈려 죽겠는 문제임.

그리고 뭐냐면, queue의 empty 체크를 안했다.
그래서 오류 한 번 나고.

이동했을 때 위치를 뱀이 있다고 표시해주는 2 표시도 해주어야 하는거고.
이래저래다..
*/
