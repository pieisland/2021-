#include<cstdio>
#include<stdio.h>
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

int n, m;
int ball[11];

int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		//cin >> ball[i];
		int weight;
		cin >> weight;
		ball[weight]++;
	}

	//이게 한 방에 되는 것이 신기하네요....
	//뒤에 있는 애들의 수를 어떻게 세어야 하나 고민했는데
	//,,, 
	int ans = 0;
	for (int i = 1; i <= m; i++) {
		n -= ball[i];
		ans += ball[i] * n;
	}

	cout << ans << endl;

	return 0;
}

/*
210227 n^2로 풀어버렸는데. 나오긴 하는데. 원하는 건 그게 아니지. n이 1000인 게 부담되는 수인지 모르겠음..
그리고 사실 이렇게 풀면 m이 전혀 소용이 없으니 이상하긴 하지..

그리고말이다. 내가 이전에 저장해둔 코드가 틀렸었다.
n에서 해당 수를 빼야되는데 안 뺐더라. 이래놓고 혼자 풀었다고 한 건 뭐니.

#include<cstdio>
#include<stdio.h>
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>
#include<cmath>

using namespace std;

int n, m;
int ball[1000];

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> ball[i];
	}

	sort(ball, ball + n);

	int cnt = 0;
	//생각해보니 정렬을 할 필요도 없는 거 아닌가.
	for (int i = 0; i < n - 1; i++) {
		int val = ball[i];
		for (int j = i + 1; j < n; j++) {
			if (val != ball[j]) cnt++;
		}
	}

	cout << cnt;

	return 0;
}
*/
