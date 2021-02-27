#include<cstdio>
#include<stdio.h>
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

/*
정렬을 해서 작은 수부터 먼저 묶는다는 것인듯.
혼자 풀 때 굉장히 복잡하게 풀어서 O(N^2) 시간 복잡도가 나왔다.
정답을 보니 쉽게 풀 수 있는 문제였다.
O(N)으로 푸네요.
count를 1씩 증가시키면서 해당 fear 값과 동일하다면 정답을 1 증가시키고
count 값을 초기화 하면 된단다.
*/

int n;
int fear[100001];

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> fear[i];
	}

	sort(fear+1, fear + n+1);

	/*int answer = 0;
	* 이건 잘못푼거. 그 이후에 fear 값이 더 커질 수 있다.
	for (int i = 1; i <= n; i++) {
		int fearLevel = fear[i];
		cout << fearLevel << " " << i << endl;
		if (i + fearLevel - 1 <= n) {
			answer += 1;
			i = i + fearLevel - 1;
		}
	}*/

	/*int idx = 1;
	int ans = 0;
	while (1) {
		int fearLevel = fear[idx];
		int cnt = 1;
		bool check = false;
		for (int i = idx + 1; i <= n; i++) {
			if (cnt == fearLevel) {
				check = true;
				break;
			}

			if (fear[i] > fearLevel) {
				fearLevel = fear[i];
			}
			cnt++;
		}
		if (!check) break;

		ans++;
		idx = idx + fearLevel;
		//cout << idx << endl;
	}*/

	int ans = 0;
	int count = 0;
	for (int i = 1; i <= n; i++) {
		count += 1;
		if (count >= fear[i]) {
			ans++;
			count = 0;
		}
	}

	cout << ans << endl;

	return 0;
}

/*
210227 다시 풀었는데 정답인지 확인할 수가 있나..

#include<cstdio>
#include<stdio.h>
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>
#include<cmath>

using namespace std;

//테스트케이스가 하나밖에 없으니 확인을 할 수도 없는데.

int arr[100000];
int n;

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];

	sort(arr, arr + n);

	int val = arr[0];
	int cnt = 1;
	int ans = 0;
	for (int i = 1; i < n; i++) {
		if (arr[i] > val) {
			if (val <= cnt) ans++;

			val = arr[i];
			cnt = 1;
		}
		else cnt++;
	}

	cout << ans << endl;

	return 0;
}
*/
