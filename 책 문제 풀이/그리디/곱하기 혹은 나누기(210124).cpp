#include<cstdio>
#include<stdio.h>
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

//0일 때가 아니라 1이하일 때였다. 1이면 곱했을 때 그 수가 나오므로 더 커지지 않기 때문이다.

using namespace std;

int main() {

	string s;
	cin >> s;
	int len = s.size();
	int answer = s[0]-'0';
	for (int i = 1; i < len; i++) {
		int num = s[i] - '0';
		if (num <=1 || answer <= 1) {
			answer += num;
		}
		else answer *= num;
	}
	cout << answer << endl;

	return 0;
}
