#include<cstdio>
#include<stdio.h>
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

int n;
int indegree[501];
int times[501];
vector<int> graph[501];
int answer[501];

/*
위상정렬이 아직 안 익숙하다.
일단 외워야 할 것 같은 느낌이 물씬 든다.

graph에 넣을 때 헷갈렸다.
다음으로 갈 노드를 넣는건데 지금 문제에서는
선수 과목 정보를 주고 있기 때문에
선수 과목에 i번째를 넣어야 했다.
나의 선수 과목에 대한 정보를 받으니 다음 과목이 아닌 선수 과목을 넣을 뻔 했다는 이야기.

아무튼 그 부분이 헷갈렸고(안 익숙해서)
시간을 갱신해줘야 했다.
구하는 건 최소의 시간이지만, 연산은 최대의 시간을 찾아야 한다.
왜냐면, 모든 것을 감싸는 시간, 즉 모두 포함할 수 있는 시간을 찾아야 하기 때문이다.

다음과목까지 듣는데 이때까지 구한 시간이랑
그 애의 이전과목까지 걸린 총 시간 + 다음 과목 듣는 시간 중 큰 수로 갱신해준다.

익숙해지는 게 관건이다.
*/

void func() {
	queue<int> q;

	for (int i = 1; i <= n; i++) {
		if (indegree[i] == 0) q.push(i);
		answer[i] = times[i];
	}

	while (!q.empty()) {
		int now = q.front();
		q.pop();
		for (int i = 0; i < graph[now].size(); i++) {
			int after = graph[now][i];
			indegree[after] -= 1;

			if(answer[after]<answer[now] + times[after])
			answer[after] = answer[now] + times[after];

			if (indegree[after] == 0) {
				q.push(after);
			}
		}
	}
}

int main() {
	
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int time;
		cin >> time;
		times[i] = time;

		while (1) {
			int num;
			cin >> num;
			if (num == -1) break;
			indegree[i]++;//먼저 들어야 하는 강의 수 
			graph[num].push_back(i);//먼저 들어야 하는 강의가 들어야 하는 강의를 넣어줌.
		}
	}

	func();
	for (int i = 1; i <= n; i++) {
		cout << answer[i] << endl;
	}

	return 0;
}
