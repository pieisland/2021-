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
