#include<cstdio>
#include<stdio.h>
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>
#include<cmath>

using namespace std;

int n;
int ugly[1000];

/*
솔직히 혼자 못 풀듯.
인덱스가 제일 헷갈림 왜 저렇게 하는건지..

2*2
2*3
2*5 같이 2를 같이 쓰려고 하는 것 같기는 한데.

아 뭐라 말을 하기가 애매한 해결방법임.....
....
*/

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	int i2 = 0, i3 = 0, i5 = 0;

	int next2 = 2, next3 = 3, next5 = 5;

	ugly[0] = 1;

	for (int i = 1; i < n; i++) {
		ugly[i] = min(next2, min(next3, next5));

		if (ugly[i] == next2) {
			i2++;
			next2 = ugly[i2] * 2;
		}
		if (ugly[i] == next3) {
			i3++;
			next3 = ugly[i3] * 3;
		}
		if (ugly[i] == next5) {
			i5++;
			next5 = ugly[i5] * 5;
		}

	}

	cout << ugly[n - 1] << '\n';


	return 0;
}
