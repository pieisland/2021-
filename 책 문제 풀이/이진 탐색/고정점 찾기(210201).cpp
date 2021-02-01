#include<cstdio>
#include<stdio.h>
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>

using namespace std;

/*
어느 상태일 때 어떻게 바꿔야되는지가 바로 이해되진 않았던 문제.
인덱스보다 해당인덱스에 있는 값이 작으면 시작을 높이고
인덱스보다 해당인덱스에 있는 값이 크면 끝을 낮추고
...
*/

int n;
int numbers[1000001];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int answer = -1;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> numbers[i];
	}
	
	int start = 0;
	int end = n - 1;
	int mid;

	while(start <= end) {
		mid = (start + end) / 2;

		if (mid > numbers[mid]) {
			start = mid + 1;
		}
		else if (mid < numbers[mid]) {
			end = mid - 1;
		}
		else {
			answer = mid;
			break;
		}
	}

	cout << answer << endl;

	return 0;
}
