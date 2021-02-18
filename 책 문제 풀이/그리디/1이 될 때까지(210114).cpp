#include<cstdio>
#include<stdio.h>
#include<iostream>

using namespace std;

/*
좀 더 효율적으로 하는 방법이 있다고 이야기를 해주는데 그게 좀 이해하기 힘들다.
1을 한 번 한 번 빼는 게 아니라 배수가 되게 하기 위해서 얼마나 빼야하는지를 바로 계산해서
한 번에 빼버린다는 것 같기는 한데. 내가 이걸 생각하겠나.
N이 100억 이상의 큰 수일 때도 빠르게 하기 위해서는 이 방법을 쓰는 게 필요하다 한다.

while(1) {
  int target = (n/k)*k; //이게 n의 배수가 되는데,
  //이 값을 만들기 위해서 1을 몇 번 이나 빼야하는지 빠르게 계산한다.
  result += (n- target);
  n= target;
  
  if(n<k) break;
  result += 1;//k로 나눴을 때
  n/= k;
}

//마지막에 남은 수에 대해서 빼서 1로 만든다.
result += n-1;

*/

int n, m;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	
	int answer = 0;
	int num = n;
	while (1) {
		if (num == 1) break;
		if (num % m == 0) {
			num = num / m;
		}
		else {
			num -= 1;
		}
		answer++;
	}
	cout << answer << '\n';

	return 0;
}
