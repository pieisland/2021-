#include<cstdio>
#include<stdio.h>
#include<iostream>

using namespace std;

/*
더 줄이려면 입력 받고나서 바로 확인해도 된다.
*/

int n, m;
int numbers[100][100];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	int answer = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> numbers[i][j];
		}
	}

	int min = 0;
	for (int i = 0; i < n; i++) {
		int tmpMin = 100000;
		for (int j = 0; j < m; j++) {
			tmpMin = numbers[i][j] < tmpMin ? numbers[i][j] : tmpMin;
		}
		if (tmpMin > min) {
			min = tmpMin;
		}
	}

	cout << min << '\n';

	return 0;
}
