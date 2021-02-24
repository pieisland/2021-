#include<cstdio>
#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
#include<queue>
using namespace std;

/*
210224 다시 풀어봣는데, 사실 문제에서 말한 행과 열은 행이 1 2 3 이런거고 열이 a b c라서
row, col을 반대로 풀기는 했다.

근데 어차피 8x8이라 동일하니까 문제가 안 난 것이다.
*/

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
