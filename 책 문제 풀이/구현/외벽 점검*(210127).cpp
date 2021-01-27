#include<cstdio>
#include<stdio.h>
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>

/*
너무 어려운 문제... 하루종일 잡고 있었던 문제...
뭐.. 여러 해결책이 있겠지만 weak을 뒤에 붙이는 게 정말 똑똑한 해결책인 것 같다.
혼자는 도저히 못 풀겠어서 책 깃허브 보고 이해했다.
나중에 혼자 풀 수 있을지 모르겠음.

next_permutation이라는 게 있는지도 몰랐다 난.
그런 것도 있구나. 굳이 내가 모든 경우를 구할 필요가 없네.

start에서 시작해서
걔부터 취약지점 길이까지 보는데 start + length
지금 보는 애로 취약지점을 메꾸지 못한다면 cnt를 증가시킨다. 
dist의 인덱스랑 cnt를 같이 쓰기 때문에 cnt가 증가하면 다음 친구로 넘어가게 되는 거다.
그리고 dist 갱신해줌...
친구를 for문에 넣는 게 아니라는 소리다.

그렇게 한 start 지점에서 확인이 끝나면 answer 값을 갱신시키고
다 못하는 경우도 확인하고 하면 된대.
너무 어렵다.....

*/

using namespace std;

int solution(int n, vector<int> weak, vector<int> dist) {
	int length = weak.size();
	for (int i = 0; i < length; i++) {
		weak.push_back(weak[i] + n);
	}

	int answer = dist.size() + 1;
	for (int start = 0; start < length; start++) {
		do {
			int cnt = 1;
			int position = weak[start] + dist[cnt - 1];

			for (int index = start; index < start + length; index++)
			{
				if (position < weak[index]) {
					cnt += 1;
					if (cnt > dist.size()) break;
					position = weak[index] + dist[cnt - 1];
				}
			}
			answer = min(answer, cnt);
		} while (next_permutation(dist.begin(), dist.end()));
	}
	if (answer > dist.size()) {
		return -1;
	}
	return answer;
}

int main() {
	
	return 0;
}
