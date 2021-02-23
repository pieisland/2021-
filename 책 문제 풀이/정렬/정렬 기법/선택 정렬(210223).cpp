#include<cstdio>
#include<stdio.h>
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>
#include<cmath>

using namespace std;

//선택 정렬
int n;
int arr[30];

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < n - 1; i++) {
		int val = arr[i];
		int idx = i;
		for (int j = i + 1; j < n; j++) {
			if (arr[j] < val) {
				val = arr[j];
				idx = j;
			}
		}

		int tmp = arr[i];
		arr[i] = val;
		arr[idx] = tmp;
	}

	for (int i = 0; i < n; i++) {
		cout << arr[i] << ' ';
	}

	return 0;

}
