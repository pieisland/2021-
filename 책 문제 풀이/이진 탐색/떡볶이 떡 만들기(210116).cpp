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
어디서 많이 봤던 문제. 회사가 좋아할 것 같은 문제.
어떤 특정한 값을 찾는 게 아니라 최적의 값을 찾는 거라서
뭔가 좀 더 어렵게 느껴지는 문제.
그래서 초반에 이게 왜 이진탐색이야? 이진탐색은 특정한 값을 찾는 문제 아니야?
라고 생각이 들었더랬다.

최적의 값을 찾을 때도 이진탐색을 사용할 수 있고
그 때 조건을 만족할 때 값을 저장해나가야 한다는 것을 잊지 않으면 될 것 같다.

++
책 내용을 조금 정리하자면,
파라메트릭 서치 문제라고 한다.
파라메트릭 서치는 최적화 문제를 결정 문제(예, 아니오로 답하는 문제)로 바꾸어 해결하는 기법을 말한다.
원하는 조건을 만족하는 가장 알맞은 값을 찾는 문제에 주로 파라메트릭 서치를 사용한다.
*/

int n, m;;
int rice[1000000];

int getRiceCakeLen(int h) {
	int ret = 0;
	for (int i = 0; i < n; i++) {
		if (rice[i] - h > 0) {
			ret += rice[i] - h;
		}
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> rice[i];
	}

	sort(rice, rice + n);

	int front = 0;
	int end = rice[n - 1];
	int height = (front + end) / 2;
	int result = 0;
	while (front<=end) {
		height = (front + end) / 2;
		int len = getRiceCakeLen(height);
		if (len < m) {
			//높이를 낮춘다.
			end = height - 1;
		}
		else {
			//길이가 이상이라는 건 높이를 더 높여봐도 된다는 것이죠
			//높이를 높인다.
			front = height + 1;
			//그리고 이렇게 될 떄의 결과를 저장해둔다. 마지막으로 저장한 값이 정답이 된다.
			result = height;
		}
	}

	cout << result << endl;

	return 0;
}
