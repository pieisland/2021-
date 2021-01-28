#include<cstdio>
#include<stdio.h>
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>

using namespace std;

/*
솔직히 처음에는 아예 이해를 못하겠었는데.. 조오오금 이해할 수 있을 것 같다.
일단 target이라는 건 초기 1을 제외하고 원소 값들을 계속 더해서 만들기 때문에
주어진 값들을 다 더해서 만들 수 있는 수에서 1 큰 수가 마지막에 나올 수 밖에 없다.
(한 번도 break이 안 되는 상태라면)

이거를 target < x 로 확인을 하는 이유는
x라는 건 그 숫자 하나만으로 만들 수 있는 값이고
target은 x가 나오기 이전의 값들이 누적이 되어서 만들어진 값이다.
그래서 target < x 의 상황이라면, 이때까지 다 더해서 만든 값보다 x가 더 큰 상황이기 때문에
만들 수 없는 값이라 하는 것이다.

target >= x 가 되는 이유는
target은 더 큰 값인데, x가 더 작을 때 그 이전 값들은 이전 원소들의 합으로 만들 수 있다는
것을 내포하고 있기 때문이다.

바로 이해가 딱 되지는 않는다만 어느정도 수긍이 됐다...

1 2 3 5 가 있다 할 때 
target : x 라면
1: 1
2: 2
4: 3(1더하면 4 된다)
7: 5(2더하면 4 된다)
12 
이렇게 되는데 

... ^0^ 그렇다..
*/

int main() {
	int n;
	vector<int> vec;
	cin >> n;
	vec.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> vec[i];
	}

	sort(vec.begin(), vec.end());

	int target = 1;
	for (int i = 0; i < n; i++) {
		int x = vec[i];
		if (target < x) {
			break;
		}
		target += x;
	}

	cout << target << '\n';
  
  return 0;
}
