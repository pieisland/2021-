#include<cstdio>
#include<stdio.h>
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

int main() {

	string s;
	cin >> s;
	int len = s.size();
	int leftSum = 0, rightSum = 0;
	for (int i = 0; i < len / 2; i++) {
		leftSum += s[i] - '0';
		rightSum += s[len - 1 - i] - '0';
	}

	if (leftSum == rightSum) cout << "LUCKY" << endl;
	else cout << "READY" << endl;

	return 0;
}

/*
210227
이번에는 for문을 두 개를 썼다.

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
	int leftSum = 0;
	int rightSum = 0;
	for (int i = 0; i < len / 2; i++) {
		leftSum += s[i] - '0';
	}
	for (int i = len / 2; i < len; i++) {
		rightSum += s[i] - '0';
	}

	if (leftSum == rightSum) {
		cout << "LUCKY";
	}
	else cout << "READY";

	return 0;
}
*/
