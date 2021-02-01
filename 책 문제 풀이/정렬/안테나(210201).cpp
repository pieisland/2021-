#include<cstdio>
#include<stdio.h>
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>

using namespace std;

/*
중간 위치가 가장 가깝다고 한다.
*/

int n;
int house[200000+1];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> house[i];
	}

	sort(house+1, house + n+1);

	cout << house[n / 2] << endl;

	return 0;
}
