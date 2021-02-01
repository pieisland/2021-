#include<cstdio>
#include<stdio.h>
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>

using namespace std;

/*
제일 처음 나오는 위치, 제일 마지막에 나오는 위치를 찾아서
계산하면 되는 문제.
*/

int n, x;
int numbers[1000000];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> x;
	for (int i = 0; i < n; i++) {
		cin >> numbers[i];
	}

	//뭔가 lowerbound, upperbound 느낌인데.
	//처음 나오는 위치, 마지막 나오는 위치를 저장한다 하면
	//위치 - 위치 +1 하면 되기는 한데

	int start = 0, end = n - 1;
	int mid = (start + end) / 2;

	int leftIdx = -1;
	while (start <= end) {
		mid = (start + end) / 2;
		if (numbers[mid] < x) {
			start = mid + 1;
		}
		else if (numbers[mid] > x) {
			end = mid - 1;
		}
		else {
			leftIdx = mid;
			end = mid - 1;
		}
	}
	int rightIdx = -1;
	start = 0, end = n - 1;
	mid = (start + end) / 2;

	while (start <= end) {
		mid = (start + end) / 2;
		if (numbers[mid] < x) {
			start = mid + 1;
		}
		else if (numbers[mid] > x) {
			end = mid - 1;
		}
		else {
			rightIdx = mid;
			start = mid + 1;
		}
	}

	if (rightIdx < 0 || leftIdx < 0)
		cout << -1 << '\n';
	else 
		cout << rightIdx - leftIdx +1 << endl;

	return 0;
}
