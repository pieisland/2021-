#include<cstdio>
#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
#include<queue>
using namespace std;

int dir[8][2] = { {2, 1}, {-2, 1}, {2, -1}, {-2, -1}, {1, 2}, {1, -2}, {-1, 2}, {-1, -2} };

bool isinside(int y, int x) {
	if (y >= 0 && y < 8 && x >= 0 && x < 8) return true;
	else return false;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	string position;
	cin >> position;
	int rowPos = position[0] - 'a';
	int colPos = position[1] - '0' - 1;

	int ans = 0;
	for (int i = 0; i < 8; i++) {
		int ny = rowPos + dir[i][0];
		int nx = colPos + dir[i][1];
		if (isinside(ny, nx)) {
			//cout << ny << nx << endl;
			ans++;
		}
	}
	cout << ans << '\n';

	return 0;
}
