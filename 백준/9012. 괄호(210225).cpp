#include<cstdio>
#include<stdio.h>
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>
#include<cmath>

using namespace std;

//스택 문제.

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;

		vector<int> vec;
		bool possible = true;
		for (int j = 0; j < s.size(); j++) {
			if (s[j] == '(') {
				vec.push_back(1);
			}
			else {
				int idx = vec.size() - 1;
				if (idx < 0) {
					possible = false;
					break;
				}
				vec.pop_back();
			}
		}
		if (vec.size() != 0) possible = false;

		if (possible) cout << "YES" << endl;
		else cout << "NO" << endl;
	}

	return 0;
}
