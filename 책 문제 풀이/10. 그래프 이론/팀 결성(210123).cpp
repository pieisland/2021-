#include<cstdio>
#include<stdio.h>
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

int n, m;
int parent[100001];

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
		int num, a, b;
		cin >> num >> a >> b;
		
		if (num == 0) {
			//팀합치기
			union_parent(a, b);
		}
		else {
			//같은팀인지 확인
			if (find_parent(a) == find_parent(b)) {
				cout << "YES" << endl;
			}
			else cout << "NO" << endl;
		}
	}

	return 0;
}

/*
210224 다시 풀었다. 특별히 다른 건 없음.

#include<cstdio>
#include<stdio.h>
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>
#include<cmath>

using namespace std;

테스트 케이스)
7 8
0 1 3
1 1 7
0 7 6
1 7 1
0 3 7
0 4 2
0 1 1
1 1 1

정답) 
NO 
NO 
YES

int n, m;
int parent[100001];

int findParent(int a) {
	if (parent[a] == a) return a;
	else return parent[a] = findParent(parent[a]);
}

void unionParent(int a, int b) {
	a = findParent(a);
	b = findParent(b);

	if (a < b) {
		parent[b] = a;
	}
	else {
		parent[a] = b;
	}
}

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	for (int i = 1; i <= n; i++) parent[i] = i;

	for (int i = 0; i < m; i++) {
		int check, team1, team2;
		cin >> check >> team1 >> team2;

		if (check == 0) {
			//팀 합치기
			unionParent(team1, team2);
		}
		else {
			//같은 팀인지 확인
			if (findParent(team1) != findParent(team2)) {
				cout << "NO" << endl;
			}
			else {
				cout << "YES" << endl;
			}
		}
	}

	return 0;
}
*/
