#include<cstdio>
#include<stdio.h>
#include<iostream>

using namespace std;

int n, m;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	
	int answer = 0;
	int num = n;
	while (1) {
		if (num == 1) break;
		if (num % m == 0) {
			num = num / m;
		}
		else {
			num -= 1;
		}
		answer++;
	}
	cout << answer << '\n';

	return 0;
}
