#include<cstdio>
#include<stdio.h>
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>

using namespace std;

/*
더한 거를 다시 넣어주고 작은거랑 다시 더해주는 거였는데
누적하는 식으로 해서 한 번 틀렸었다.
우선순위 큐로 해결..
큰 수가 먼저 나오게 정렬이 되기 때문에
마이너스를 붙여 넣어주면 작은수를 먼저 꺼낼 수 있다.
*/

int n;
priority_queue<int> pq;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		pq.push(-num);
	}

	int answer = 0;
	while (!pq.empty()) {
		int n1 = -pq.top();
		pq.pop();
		if (pq.empty()) break;
		int n2 = -pq.top();
		pq.pop();
		answer += n1 + n2;
		pq.push(-n1 - n2);
	}

	cout << answer << endl;
	
	return 0;
}
