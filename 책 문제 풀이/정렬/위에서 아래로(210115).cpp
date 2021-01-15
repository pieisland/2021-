#include<cstdio>
#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
#include<queue>
using namespace std;

//vector resize로 원하는 크기 설정 가능.

int n;
vector<int> arr;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	arr.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	sort(arr.begin(), arr.end());

	for (int i = n - 1; i >= 0; i--) {
		cout << arr[i] << " ";
	}

	return 0;
}
