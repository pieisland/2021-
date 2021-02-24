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

/*
210224 다시 풀어보았다.

#include<cstdio>
#include<stdio.h>
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>
#include<cmath>

using namespace std;

와 그래도 혼자 구현했습니다. 안익숙해서 시간이 많이 걸리긴 했지만.
추카포카.
알려주는 건 선수 과목인데, 넣는 거는 다음 과목을 넣어야 해서
거기서 좀 헷갈렸었다.

다음과목을 넣어야 선수 과목이 다음 과목의 차수를 줄여줄 수 있으니
헷갈려도 더 집중하고 하는 수 밖에.

근데 위상정렬문제는
차수 배열도 필요하고, 후수 과목 정보도 저장해야되고,
이 문제의 경우는 시간 정보도 저장하고 해야되어서 되게 뭔가 많이 필요한 문제였다.

테스트케이스)
5
10 - 1
10 1 - 1
4 1 - 1
4 3 1 - 1
3 3 - 1

답)
10 
20
14
18
17


int n;
vector<int> subject[501];

int degree[501];
int times[501];
int listentime[501];

queue<int> q;

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		int time;
		cin >> time;//해당 강의의 시간
		times[i] = time;//강의 시간

		//선수 강의
		while (1) {
			int node;
			cin >> node;
			if (node == -1) break;

			//다음 강의 넣어주기
			subject[node].push_back(i);
			
			//선수 과목 개수만큼 차수 올려준다.
			degree[i]++;
		}

		//선수과목이 없으면..
		if (degree[i] == 0) {
			q.push(i);
			listentime[i] = times[i];
		}
	}

	//degree가 0인 애들이 들어있는데
	while (!q.empty()) {
		int cnode = q.front();
		q.pop();

		//다음 과목들에 대해서.
		for (int i = 0; i < subject[cnode].size(); i++) {
			int nnode = subject[cnode][i];
			//차수 빼주고
			degree[nnode] -= 1;

			//내 선수 과목들은 거 + 내 과목 듣기 / 이전까지 구해놓은 내 과목 듣는 시간
			listentime[nnode] = max(listentime[cnode] + times[nnode], listentime[nnode]);

			if (degree[nnode]==0) {
				q.push(nnode);
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		cout << listentime[i] << '\b';
	}

	return 0;
}
*/
