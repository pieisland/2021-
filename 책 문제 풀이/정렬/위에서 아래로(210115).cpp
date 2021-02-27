#include<cstdio>
#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
#include<queue>
using namespace std;

//vector resize로 원하는 크기 설정 가능.

int n;
vector<int> arr;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	arr.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	sort(arr.begin(), arr.end());

	for (int i = n - 1; i >= 0; i--) {
		cout << arr[i] << " ";
	}

	return 0;
}

/*
210227
sort를 사용해서 큰 수에서 작은 수로 정렬하는 버전. 이전에 푼거는 출력만 그렇게 한 거고.

#include<cstdio>
#include<stdio.h>
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>
#include<cmath>

using namespace std;

int arr[1000];
int n;

bool cmp(int a, int b) {
	return a > b;
}

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];

	sort(arr, arr + n, cmp);

	for (int i = 0; i < n; i++) cout << arr[i] << ' ';

	return 0;
}
*/
