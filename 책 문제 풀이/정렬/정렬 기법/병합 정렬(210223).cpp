#include<cstdio>
#include<stdio.h>
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>
#include<cmath>

using namespace std;

//병합 정렬
int n;
int arr[30];
int sorted[30];

void merge(int left, int mid, int right) {
	int i, j, k, l;
	i = left; //왼쪽 부분정렬 시작 위치
	j = mid + 1; //오른쪽 부분정렬 시작 위치
	k = left;//정렬 저장할 시작 위치

	while (i <= mid && j <= right) {
		if (arr[i] <= arr[j]) {
			sorted[k++] = arr[i++];
		}
		else {
			sorted[k++] = arr[j++];
		}
	}

	if (i > mid) {
		for (l = j; l <= right; l++) {
			sorted[k++] = arr[l];
		}
	}
	else {
		for (l = i; l <= mid; l++) {
			sorted[k++] = arr[l];
		}
	}

	for (l = left; l <= right; l++) {
		arr[l] = sorted[l];
	}
}

void mergeSort(int left, int right) {
	int mid;

	if (left < right) {
		mid = (left + right) / 2;
		mergeSort(left, mid);
		mergeSort(mid + 1, right);
		merge(left, mid, right);
	}
}

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	mergeSort(0, n-1);

	for (int i = 0; i < n; i++) {
		cout << arr[i] << ' ';
	}

	return 0;

}
