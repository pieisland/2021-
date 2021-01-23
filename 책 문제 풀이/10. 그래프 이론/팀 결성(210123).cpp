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
