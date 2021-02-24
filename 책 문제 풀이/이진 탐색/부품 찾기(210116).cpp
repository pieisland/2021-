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

/*
210224 다시 풀었다. 딱히 풀이가 다른 건 아닌데. 이전에 푼 게 출력 형식이 틀렸더라 ㅋㅋ...;
*/

/*
#include<cstdio>
#include<stdio.h>
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>
#include<cmath>

using namespace std;

int n;
int m;
int arr[1000000];
int findObj[100000];

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	sort(arr, arr + n);

	cin >> m;
	for (int i = 0; i < m; i++) {
		//cin >> findObj[i];
		int obj;
		cin >> obj;

		int start = 0;
		int end = n - 1;
		int mid;
		bool isFound = false;
		while (start <= end) {
			int mid = (start + end) / 2;
			if (arr[mid] < obj) {
				//찾는 값보다 작으면
				start = mid + 1;
			}
			else if (arr[mid] > obj) {
				//찾는 값보다 크다면
				end = mid - 1;
			}
			else {
				//찾는 값이면
				isFound = true;
				break;
			}
		}
		if (isFound) {
			cout << "yes" << ' ';
		}
		else {
			cout << "no" << ' ';
		}
	}

	return 0;
}
*/
