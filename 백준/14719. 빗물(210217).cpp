#include<cstdio>
#include<stdio.h>
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>

using namespace std;

/*
예전에 이런 문제가 코테 문제로 나왔었다.
*/

int h, w;
int arr[500];

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> h >> w;
	for (int i = 0; i < w; i++) {
		cin >> arr[i];
	}

	int ans = 0;
	for (int i = 1; i < w - 1; i++) {
		int leftHigh = 0;
		int rightHigh = 0;

		for (int j = i - 1; j >= 0; j--) {
			if (arr[j] >= leftHigh) {
				leftHigh = arr[j];
			}
		}

		for (int j = i + 1; j < w; j++) {
			if (arr[j] >= rightHigh) {
				rightHigh = arr[j];
			}
		}

		int val = min(leftHigh, rightHigh);
		if (val == 0 || val < arr[i]) continue;

		ans += val - arr[i];
	}

	cout << ans << endl;

	return 0;
}
