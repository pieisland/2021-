#include<cstdio>
#include<stdio.h>
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

/*
뭉텅이의 개수를 세어 비교하는 문제.
*/

int main() {

	string s;
	cin >> s;
	int len = s.size();

	int zeroCnt = 0, oneCnt = 0;

	int val = s[0] - '0';
	if (val == 0) zeroCnt++;
	else oneCnt++;

	for (int i = 1; i < len; i++) {
		int num = s[i] - '0';
		if (num != val) {
			val = num;
			if (val == 0) zeroCnt++;
			else oneCnt++;
		}
	}

	if (zeroCnt < oneCnt) cout << zeroCnt << endl;
	else cout << oneCnt << endl;

	return 0;
}
