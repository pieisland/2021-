#include<cstdio>
#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
#include<queue>
using namespace std;

/*
이진탐색 문제는 면접에서도 잘 나오는 문제다.
값이 아닐 때 mid를 주는 게 아니라 +1, -1 했었구나.
하긴 이미 아닌 값이었으니까.

데이터의 개수가 1000만 개를 넘어가거나 탐색 범위의 크기가 1000억 이상이면
이진 탐색 알고리즘을 의심해 보라 했다.
*/

int n, m;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	vector<int> obj;
	obj.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> obj[i];
	}

	sort(obj.begin(), obj.end());
	cin >> m;
	for (int i = 0; i < m; i++) {
		int num;
		cin >> num;

		int front = 0, end = n - 1;
		bool isPossible = false;
		while (1) {
			if (front > end) break;
			int mid = (front + end) / 2;
			if (num<obj[mid]) {
				end = mid - 1;
			}
			else if (obj[mid] < num) {
				front = mid + 1;
			}
			else {
				isPossible = true;
				break;
			}
		}
		if (isPossible) {
			cout << "yes" << '\n';
		}
		else cout << "no" << '\n';
	}

	return 0;
}
