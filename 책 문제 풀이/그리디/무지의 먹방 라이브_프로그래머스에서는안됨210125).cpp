#include<cstdio>
#include<stdio.h>
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

//프로그래머스에서 왜 while문을 못 빠져나오는지 모르겠다.
//비주얼스튜디오에서는 정상 작동 한다.
//그리디는 아직 먼 것 같다. 해결책을 혼자 생각 못하겠음.
//역시 카카오 문제는...

using namespace std;

int solution(vector<int> vec, long long k) {
	long long sum = 0, before = 0;
	priority_queue<pair<int, int>> food_times;
	for (int i = 0; i < vec.size(); i++) {
		sum += vec[i];
		//음수로 넣어야 제일 작은 값을 먼저 꺼낼 수 있다.
		//기본 값이 max heap으로 작은 값부터 큰 값 순으로 꺼내게 되기 때문이다.
		food_times.push({ -vec[i], i + 1 });
	}
	if (sum <= k) return -1; //다음에 먹을 거 없음.

	while ((-food_times.top().first - before)*food_times.size()<=k) {
		k -= (-food_times.top().first) * food_times.size();
		before = -food_times.top().first;
		food_times.pop();
		cout << 111 << endl;
	}

	vector<pair<int, int>> tmp;
	while (!food_times.empty()) {
		tmp.push_back({ food_times.top().second, food_times.top().first * -1 });
		food_times.pop();
		cout << 2222 << endl;
	}
	sort(tmp.begin(), tmp.end());
	return tmp[k % tmp.size()].first;
}
