#include<cstdio>
#include<stdio.h>
#include<iostream>

using namespace std;

int n, m, k;
int numbers[1000];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		cin >> numbers[i];
	}

	sort(numbers, numbers+n);
	int firstBig = numbers[n - 1];
	int secondBig = numbers[n - 2];

	int answer = 0;
	int cnt = 0;
	for (int i = 0; i < m; i++) {
		if (cnt == k) {
			answer += secondBig;
			cnt = 0;
		}
		else {
			answer += firstBig;
			cnt++;
		}
	}

	cout << answer << '\n';

	//2번째 방법. 수학적으로 해결.
	cnt = (m / (k + 1)) * k;
	cnt += m % (k + 1);
	
	answer = cnt * firstBig;
	answer += (m - cnt) * secondBig;

	cout << answer << '\n';

	return 0;
}
