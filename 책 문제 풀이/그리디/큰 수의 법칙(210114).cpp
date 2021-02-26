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

//210227
//하나하나 하는 식 말고 수학적 계산으로 하는 방식으로 풀었다.

int arr[1000];
int n, m, k;

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) cin >> arr[i];

	sort(arr, arr + n);
	int firstBig = arr[n - 1];
	int secondBig = arr[n - 2];

	int answer = 0;
	int moc = m / (k + 1);
	int nam = m % (k + 1);
	answer += (firstBig * k * moc);
	answer += (secondBig * moc);
	answer += firstBig * nam;

	cout << answer;

	return 0;
}
*/
