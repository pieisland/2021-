#include<cstdio>
#include<stdio.h>
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>
#include<cmath>

using namespace std;

int v, e, k;
int INF = 987654321;
vector<pair<int, int>> vec[20001];
int connection[20001];

void dijkstra() {
	priority_queue<pair<int, int>> pq;
	pq.push({ 0, k });
	connection[k] = 0;

	while (!pq.empty()) {
		int cost = -pq.top().first;
		int currentNode = pq.top().second;
		pq.pop();

		for (int i = 0; i < vec[currentNode].size(); i++) {
			int nextNode = vec[currentNode][i].first;
			int edgeCost = vec[currentNode][i].second;

			if (edgeCost + cost < connection[nextNode]) {
				connection[nextNode] = edgeCost + cost;
				pq.push({ -(edgeCost + cost), nextNode });
			}
		}
	}
}

void initConnection() {
	for (int i = 0; i < 20001; i++) {
		connection[i] = INF;
	}
}

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> v >> e;
	cin >> k;
	initConnection();

	for (int i = 0; i < e; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		vec[u].push_back({ v, w });
	}

	dijkstra();

	for (int i = 1; i <= v; i++) {
		if (connection[i] == INF)
			cout << "INF" << '\n';
		else cout << connection[i] << '\n';
	}

	return 0;
}
