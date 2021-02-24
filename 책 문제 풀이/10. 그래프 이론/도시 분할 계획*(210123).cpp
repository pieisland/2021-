#include<cstdio>
#include<stdio.h>
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

/*
두 지역으로 어떻게 분리하지? 모든 경우의 수 해야되나..?
했는데 그게 아니었다.
이 문제는 단순히 두 지역이어서 먹히는 거기도 하겠지만...
일단 되는 애들을 다 묶어두고 그중에서 가장 큰 걸 끊으면 되는거란다.
그러면 자연스레 두 개로 나누어지기 때문.
이런 아이디어는 종종 다른 문제에서도 보이긴 하는데
솔직히.. 매번, 모든 경우의 수를 사용해야 하나? 하는 생각부터 먼저 들어서
확 와닿지는 않는 것 같다... 익숙해져야 하는 문제.
*/

int n, m;
int parent[100001];
vector<pair<int, pair<int, int>>> edges;

int find_parent(int x) {
	if (x != parent[x]) {
		parent[x] = find_parent(parent[x]);
	}

	return parent[x];
}

void union_parent(int a, int b) {
	a = find_parent(a);
	b = find_parent(b);
	if (a < b) parent[b] = a;
	else parent[a] = b;
}

int main() {
	
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		parent[i] = i;
	}

	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		edges.push_back({ c, {a, b} });

	}

	sort(edges.begin(), edges.end());

	int result = 0;
	int maxVal = 0; //뺄 간선. 최소 신장트리에 포함되는 간선 중 가장 큰 간선

	for (int i = 0; i < m; i++) {
		int cost, a, b;
		cost = edges[i].first;
		a = edges[i].second.first;
		b = edges[i].second.second;

		if (find_parent(a) != find_parent(b)) {
			union_parent(a, b);
			result += cost;

			//어차피 간선 순으로 정렬해서 괜찮다.
			maxVal = cost;
		}
	}

	result -= maxVal;
	cout << result << endl;

	return 0;
}

/*
210224 다시 풀었다. 이번에도 혼자 못 풀었다. 왜냐면 크루스칼 푸는 방법을 잊음.

#include<cstdio>
#include<stdio.h>
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>
#include<cmath>

using namespace std;

크루스칼 알고리즘은 아직 안 익숙하네.
연결에 대한 정보 다 저장하고 정렬한 후에
크기 작은 간선부터 꺼내서 두 개가 서로 부모 다를 때만 이어준다.

크루스칼 쓸 때 하는 건 이게 방향이 없는 거여야 하는거겠지?

테스트케이스) 
7 12
1 2 3
1 3 2
3 2 1
2 5 2
3 4 4
7 3 6
5 1 5
1 6 2
6 4 1
6 5 3
4 5 3
6 7 4

정답) 8


int n, m;
vector<pair<int, pair<int, int>>> edges;
int parent[100001];

int findParent(int a) {
	if (parent[a] == a) return a;
	else return parent[a] = findParent(parent[a]);
}

void unionParent(int a, int b) {
	a = findParent(a);
	b = findParent(b);
	if (a < b) parent[b] = a;
	else parent[a] = b;
}

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		parent[i] = i;
	}

	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		edges.push_back({ c, {a, b} });
	}

	sort(edges.begin(), edges.end());

	int costSum = 0;
	int maxVal;
	for (int i = 0; i < m; i++) {
		int cost = edges[i].first;
		int a = edges[i].second.first;
		int b = edges[i].second.second;

		if (findParent(a) != findParent(b)) {
			unionParent(a, b);
			costSum += cost;

			maxVal = cost;
		}
	}

	cout << costSum - maxVal;

	return 0;
}
*/
