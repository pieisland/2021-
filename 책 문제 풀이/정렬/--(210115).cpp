#include<cstdio>
#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
#include<queue>
using namespace std;

int n, k;
int arr1[100000];
int arr2[100000];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> arr1[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> arr2[i];
	}
	
	sort(arr1, arr1 + n);
	sort(arr2, arr2 + n);

	int lastidx = n - 1;
	for (int i = 0; i < k; i++) {
		if (arr1[i] < arr2[lastidx]) {
			arr1[i] = arr2[lastidx];
			lastidx--;
		}
		else {
			break;
		}
	}

	int ans = 0;
	for (int i = 0; i < n; i++) {
		ans += arr1[i];
	}
	cout << ans << '\n';

	return 0;
}
