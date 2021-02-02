#include<cstdio>
#include<stdio.h>
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>

using namespace std;

/*
놀랍게도 1년 전에는 풀었던 문제였다.
지금은 아무 생각도 나지 않았다.
^0^.... 정말 마주하기 싫은 현실이다.

0번째는 무조건 설치한다고 생각한다.
초반에 거리는 1, 0번째와 n-1번째 차이를 최소와 최대로 잡는다.
간격은 해당 거리의 절반인 mid로 잡는다.

그 간격이상으로 설치할 수 있는 곳이면 설치한다고 하고 개수를 센다.
세어서 c 이상이면 일단 저장하고 간격을 늘려서 줄여본다.
c보다 작으면 간격을 줄여본다.

그렇게 하다보면 마지막에 저장되는 result 값이 정답이 된다.
*/

int n, c;
int home[200000];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> c;
	for (int i = 0; i < n; i++) {
		cin >> home[i];
	}
	sort(home, home + n);

	//거리의 최솟값과 최댓값
	//책이 틀렸었네... home[1]-home[0]이 최소는 아니니까요....
	//그 둘의 간격이 클 수도 있는 거라.
	int start = 1;
	int end = home[n - 1] - home[0];
	
	int result;
	while (start <= end) {
		int mid = (start + end) / 2;

		int cnt = 1;
		int idx = 0;
		for (int i = 1; i < n; i++) {
			//설치하는 거리가 간격 이상이면 설치 가능
			if (home[i] - home[idx] >= mid) {
				cnt++;
				//마지막 설치한 위치 업데이트
				idx = i;
			}
		}

		//원래 설치하려던 것 이상이면 일단 저장하고 거리를 늘려서 설치 개수를 줄여본다.
		if (cnt >= c) {
			//거리를 늘려본다.
			start = mid + 1;
			result = mid;
		}
		else { //cnt < c 설치 거리가 멀다는 뜻이다.
			//거리를 줄여본다.
			end = mid - 1;
		}
	}

	cout << result << '\n';

	return 0;
}
