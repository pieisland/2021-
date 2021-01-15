#include<cstdio>
#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
#include<queue>
using namespace std;

//vector.resize 썼다가 시간 날려먹었다.

int n;

vector<pair<int, string>> vec;
vector<pair<int, int>> vec2;
vector<string> strvec;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		string str;
		int score;
		cin >> str >> score;
		vec.push_back({ score, str });
	}

	sort(vec.begin(), vec.end());

	for (int i = 0; i < n; i++) {
		cout << vec[i].second << ' ';
	}

	return 0;
}
