#include<cstdio>
#include<stdio.h>
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>

using namespace std;

/*
* 오랜만이네요. 가장 긴 증가하는 부분수열 문제였구나.
* 기억도 안난다.....
* 그런 문제와 풀이법이 있다는 건 경험이야 해봤다만
* 뭐가 그런문제인지 아직 파악을 못하는걸까?
* 
* 하하하하하.
* 
* 아무튼간에. 자기자신을 먼저 가진다고 생각하고 1로 한 다음에
* 나보다 인덱스 작은 애들을 보면서 걔들을 포함할 수 있는지 보고
* 걔 +1 값이 나보다 크면 갱신해준다.
* 
* n^2 풀이 말고 nlogn으로 푸는 방법도 있었던 것 같지만
* 뭔가 더 복잡했다. 다시 찾아봐야될 것 같기는 한데.
*/

/*
O(nlogn)으로 푸는 방법

이 문제는 LIS의 반대 버전인 감소하는 것을 찾기 때문에
arr를 그대로 사용하는 게 아니라 반대로 뒤집어서 해야 O(nlogn)의 LIS 알고리즘을 쓸 때 편할 것이다. 

int newArr[2000];
for(int i=0;i<n;i++) {
	newArr[i] = arr[n-1-i];
}

vector<int> ans;
ans.push_back(newArr[0]);

int idx=0;
for(int i=1;i<n;i++) {
	if(ans[idx] <newArr[i])
	{
		ans.push_back(newArr[i]);
		idx++;
	}
	else {
		auto it = lower_bound(ans.begin(), ans.end(), newArr[i]);
		*it = newArr[i];
	}
}

cout << n - ans.size() <<'\n';

*/

int n;
int arr[2000];
int dp[2000];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		dp[i] = 1;
	}

	for (int i = 1; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (arr[j] > arr[i]) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
	}

	/*for (int i = 0; i < n; i++) {
		cout << dp[i] << ' ';
	}*/
	
	int maxval = 0;
	for (int i = 0; i < n; i++) {
		maxval = max(maxval, dp[i]);
	}

	cout << n - maxval << endl;

	return 0;
}
