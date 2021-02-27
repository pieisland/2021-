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

/*
210227
어차피 똑같이 풀었다.

#include<cstdio>
#include<stdio.h>
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>
#include<cmath>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	string s;
	cin >> s;
	int len = s.size();

	int zeroCnt = 0;
	int oneCnt = 0;
	int val;
	if (s[0] == '0') zeroCnt++;
	else oneCnt++;
	val = s[0];
	for (int i = 1; i < len; i++) {
		if (s[i] != val) {
			if (s[i] == '0') zeroCnt++;
			else oneCnt++;
			val = s[i];
		}
	}

	int ans = min(zeroCnt, oneCnt);
	cout << ans;

	return 0;
}
*/
