#include<cstdio>
#include<stdio.h>
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>

/*
* 오름차순으로 모든 경우의 수를 구하는 걸 잠시 있었다.
* start를 설정해주고 dfs 돌리는건데.. 제발 좀 기억하자.
* 
* 최대 m개라고 해서 1부터 m개까지 봐야하나 했지만, 그럴 필요가 없다.
* 왜냐하면, 최대를 잡아야 당연히 최소 거리가 나올 것이기에...
* 
* 그래서 그냥 m개를 픽하고 나서 경로 계산을 해보면 되는 문제였다.
* 
* 중간에 집이랑 치킨집이랑 순서 헷갈려서 시간을 좀 버렸다.
* 그 전에는 start가 m 이상일 때 멈추라고 해서... 제대로 안나왔었다. 바보임..
*/

using namespace std;

int n, m;
int board[50][50];
int sel[13];
vector<pair<int, int>> home;
vector<pair<int, int>> chicken;
int ans = 987654321;

int getChickenDist() {
	int dist = 0;

	for (int i = 0; i < home.size(); i++) {
		int tmpdist = 987654321;
		for (int j = 0; j < chicken.size(); j++) {
			if (sel[j] == 0) continue;
			int dy = chicken[j].first - home[i].first;
			int dx = chicken[j].second - home[i].second;
			if (dy < 0) dy = -dy;
			if (dx < 0) dx = -dx;

			if (tmpdist > dy + dx) tmpdist = dy + dx;
		}
		//구해진 가장 작은 dist를 넣는다.
		dist += tmpdist;
	}

	return dist;
}

void pick(int start, int cnt, int m) {
	if (cnt == m) {
		int dist = getChickenDist();
		if (dist < ans)ans = dist;

		return;
	}

	if (start >= chicken.size()) {
		return;
	}

	for (int i = start; i < chicken.size(); i++) {
		if (sel[i]) continue;
		sel[i] = 1;
		pick(i + 1, cnt + 1, m);
		sel[i] = 0;
	}
}

int main() {
	//0 빈칸, 1 집, 2 치킨집
	//m은 최대 치킨 집 개수
	cin >> n >> m;
	for (int i=0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
			if (board[i][j] == 2)
				chicken.push_back({ i, j });
			else if (board[i][j] == 1) {
				home.push_back({ i, j });
			}
		}
	}

	pick(0, 0, m);

	cout << ans << '\n';

	return 0;
}
