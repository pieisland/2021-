#include<cstdio>
#include<stdio.h>
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

int n, m;
int ball[11];

int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		//cin >> ball[i];
		int weight;
		cin >> weight;
		ball[weight]++;
	}

	//이게 한 방에 되는 것이 신기하네요....
	//뒤에 있는 애들의 수를 어떻게 세어야 하나 고민했는데
	//,,, 
	int ans = 0;
	for (int i = 1; i <= m; i++) {
		ans += ball[i] * n;
	}

	cout << ans << endl;

	return 0;
}
