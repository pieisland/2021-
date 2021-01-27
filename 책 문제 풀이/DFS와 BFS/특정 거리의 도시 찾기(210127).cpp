#include<cstdio>
#include<stdio.h>
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>

using namespace std;

/*
진심으로 하는 말인데
진짜 다익스트라는 주기적으로 풀어줘야 할 것 같다.
할 때마다 기억 안난다.
거의 뭐 맨인블랙 빛 본 것 같음.

다익스트라 알면 푸는 것 자체는 어렵지는 않았다.
얘는 연결된 애의 거리가 각각 다른 게 아니기 때문에
그냥 1을 더해주면 됐다.
*/

int n, m, k, x;
vector<int> con[300001];
long long d[300001];

void dijkstra() {
	priority_queue<pair<int, int>> pq;
	pq.push({0, x});

	d[x] = 0;

	while (!pq.empty()) {
		int now = pq.top().second;
		int dist = -pq.top().first;
		pq.pop();

		for (int i = 0; i < con[now].size(); i++) {
			int next = con[now][i];
			int nextDistance = dist + 1;

			if (d[next] > nextDistance) {
				d[next] = nextDistance;
				pq.push({-nextDistance, next});
			}
		}
	}
}

void initDist() {
	for (int i = 0; i <= 300000; i++) {
		d[i] = 987654321;
	}
}

int main() {
	
	cin >> n >> m >> k >> x;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		con[a].push_back(b);
	}

	initDist();
	dijkstra();

	int cnt = 0;
	for (int i = 0; i <= n; i++) {
		
		if (d[i] == k) {
			cnt++;
			cout << i << '\n';
		}
	}
	if (cnt == 0)
		cout << -1 << '\n';

	return 0;
}
