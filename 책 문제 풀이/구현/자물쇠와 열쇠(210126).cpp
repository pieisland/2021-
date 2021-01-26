#include<cstdio>
#include<stdio.h>
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>

using namespace std;

/*
완전탐색 문제인데 구현이 꽤 까다롭다.
할 일 많겠네.. 하는 생각이 딱 드는 문제였다.

회전을 할 때 인덱스의 변화는 직접 그려보는 게 훨씬 쉽다.
시계방향, 반시계방향 회전 때 다르게 나오기 때문에 경우를 나누어 처리했다.
-> 근데 다시 생각해보니 한 방향으로만 보면 된다. 시계방향이나 반시계방향이나 돌았을 때
결국 나오는 형태가 동일하다.

자물쇠의 구멍과 열쇠의 돌기만 맞아 떨어진다고 정답이 되는 건 아니다.
다른 부분에 대해서도 맞게 떨어져야 하기 때문에 개수를 세는 게 세 개나 된다.
(가령 자물쇠 구멍이랑 열쇠 돌기는 맞았지만, 다른 부분에서 돌기 돌기가 만나게 되는 경우
정답이 될 수 없다)

그리고 맞추는 걸 자물쇠 안에서만 열쇠를 맞추는 게 아니라
밖에 나가서도 맞출 수 있기 때문에 범위에 대해서도 신경 써줘야 한다.

nxn 크기의 자물쇠에 mxm 크기의 열쇠를 맞추려 하는데....
for문 범위가 더 헷갈림...
a+i가 너무 헷갈림.... 창을 만드는 거라고 생각하면 된다.
....
*/

vector<vector<int>> clockWise(int r, vector<vector<int>> key) {
	vector<vector<int>> ret = key;

	int n = key.size();
	for (int rot = 0; rot < r; rot++) {
		vector<vector<int>> tmp = ret;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				tmp[i][j] = ret[n - 1 - j][i];
			}
		}
		ret = tmp;
	}

	return ret;
}

vector<vector<int>> counterClockWise(int r, vector<vector<int>> key) {
	vector<vector<int>> ret = key;

	int n = key.size();
	for (int rot = 0; rot < r; rot++) {
		vector<vector<int>> tmp = ret;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				tmp[i][j] = ret[j][n - 1 - i];
			}
		}
		ret = tmp;
	}
	return ret;
}

vector<vector<int>> rotate(int r, vector<vector<int>> key) {
	vector<vector<int>> ret;

	if (r == 0) return key;
	else
	{
		if (r > 0 && r < 4) {
			ret = clockWise(r, key);
		}
		else if (r >= 4 && r < 7) {
			ret = counterClockWise(r - 3, key);
		}
	}

	return ret;
}

bool isinside(int y, int x, int n)
{
	if (y >= 0 && y < n && x >= 0 && x < n) return true;
	else return false;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
	bool answer = true;
	int m = key.size();
	int n = lock.size();

	int hole = 0; //총 구멍의 개수를 센다.
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (lock[i][j] == 0) hole++;
		}
	}

	for (int r = 0; r < 7; r++) { //주어진대로 한 번, 시계방향 세 번 회전, 반시계방향 세 번 회전
		vector<vector<int>> newKey = rotate(r, key);

		//하나만 맞는 경우도 확인하기 위함.
		//0-m+1로 계산이 되어 1-m이라 했다.
		for (int a = 1 - m; a < n; a++) {
			for (int b = 1 - m; b < n; b++) {
				int check = 0;
				int c1 = 0;
				int c2 = 0;
				for (int i = 0; i < m; i++) {
					for (int j = 0; j < m; j++) {
						//범위 벗어나는 곳은 안본다.
						if (!isinside(a + i, b + j, n)) {
							continue;
						}
						//벗어나지 않는 개수
						c1++;
						if (lock[a + i][b + j] + newKey[i][j] == 1) {
							//자물쇠와 열쇠가 맞아떨어지는 경우
							c2++;
						}
						//자물쇠의 구멍에 키의 돌기가 맞는 경우
						if (lock[a + i][b + j] == 0 && newKey[i][j] == 1) {
							check++;
						}
					}
				}

				//자물쇠 구멍있는 곳이 딱 맞으면서 다른 곳도 문제 없는 경우
				if (hole == check && c1 == c2) {
					return true;
				}
			}
		}
	}

	return false;
}
