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

void quickSort(int left, int right) {
	int tmp;
	if (left >= right) return;
	int pivot = arr[left];
	int i = left + 1;
	int j = right;

	while (1) {
		//왼쪽에서 pivot보다 큰 값을 찾는다.
		while (pivot > arr[i] && i < right) i++;
		
		//오른쪽에서 pivot보다 작은 값을 찾는다.
		while (pivot < arr[j] && j > left) j--;

		//엇갈림
		if (i >= j) break;

		tmp = arr[i];
		arr[i] = arr[j];
		arr[j] = tmp;
	}

	tmp = arr[j];
	arr[j] = pivot;
	arr[left] = tmp;

	quickSort(left, j - 1);
	quickSort(j + 1, right);
}

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	quickSort(0, n - 1);

	for (int i = 0; i < n; i++) {
		cout << arr[i] << ' ';
	}

	return 0;

}
