#include<cstdio>
#include<stdio.h>
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>
#include<cmath>

using namespace std;

//삽입 정렬
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

	int i, j;
	for (i = 1; i < n; i++) {
		int val = arr[i];
		for (j = i - 1; j >= 0; j--) {
			if (arr[j] <= val) break;//이미 정렬 돼있다.
			arr[j + 1] = arr[j];
		}
		arr[j + 1] = val;
	}

	/*
	//책에서 소개한 방법
	for (int i = 1; i < n; i++) {
		for (int j = i; j >= 0; j--) {
			if (arr[j - 1] > arr[j]) {
				int tmp = arr[j];
				arr[j] = arr[j - 1];
				arr[j - 1] = tmp;
			}
			else break;
		}
	}

	*/
	
	for (int i = 0; i < n; i++) {
		cout << arr[i] << ' ';
	}

	return 0;

}
