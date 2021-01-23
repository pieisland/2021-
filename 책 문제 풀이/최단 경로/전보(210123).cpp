#include<cstdio>
#include<stdio.h>
#include<iostream>
#include<vector>
#include<queue>

using namespace std;

//210123
//다익스트라 너무 오랜만. 3개월만에 풀어본다.
//그래서 다 까먹음. ..^0^ 진짜 너무 싫다. 무한 반복임.
//2중 포문 써서 쓰는 거랑은 다르게 달리 이미 방문했는지 여부를 안 보는 것 같은데
//큐를 사용하는 것 자체가 방문 처리를 한다는 걸까.
//거리로 걸러지는건가?

int n, m, c;
vector<pair<int, int>> con[30001];
int dist[30001];
int INF = 987654321;

void dijkstra(int start) {
	dist[start] = 0;

	//우선 순위 큐라는 걸 잊지 말자.
	priority_queue<pair<int, int>> q;
	q.push({ 0, start });

	while (!q.empty()) {
		//우선 순위 큐는 front가 아니라 top을 쓴다.
		int distance = -q.top().first;
		int current = q.top().second;
		q.pop();

		for (int i = 0; i < con[current].size(); i++) {
			int next = con[current][i].first;
			int nextDistance = distance + con[current][i].second;
		
			if (nextDistance < dist[next]) {
				dist[next] = nextDistance;

				//넣을 때 음수로 넣어야 가장 작은 값이 먼저 나온다.
				q.push({ -nextDistance, next });
			}
		}
	}
}

int main() {

	cin >> n >> m >> c;
	for (int i = 0; i < m; i++) {
		int x, y, z;
		cin >> x >> y >> z;

		//연결
		con[x].push_back({ y, z });
	}

	//초기화
	for (int i = 0; i <= n; i++) dist[i] = INF;

	//c에서 다른 정점으로 가는 최단 거리 구하기.
	dijkstra(c);
	
	int ans1 = 0;
	int ans2 = 0;
	for (int i = 1; i <= n; i++) {
		if (i == c) continue;
		if (dist[i] < INF) {
			ans1++;
			if (ans2 < dist[i]) ans2 = dist[i];
		}
	}

	cout << ans1 << ' ' << ans2 << '\n';

	return 0;
}
