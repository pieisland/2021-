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
	int numSum = 0;
	vector<char> alpha;
	for (int i = 0; i < len; i++) {
		if (s[i] >= '0' && s[i] <= '9') numSum += s[i] - '0';
		else alpha.push_back(s[i]);
	}
	sort(alpha.begin(), alpha.end());
	
	for (int i = 0; i < alpha.size(); i++) {
		cout << alpha[i];
	}
	cout << numSum << '\n';
	
	return 0;
}

/*
210228 다시 풀었는데 그냥 동일하게 풀었다.
*/
