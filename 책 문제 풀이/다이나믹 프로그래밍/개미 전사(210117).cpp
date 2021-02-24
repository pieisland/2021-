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
뭔가 코테 문제랑 좀 비슷한 것 같으면서도 다른 문제다..
*/

/*
전형적인 문제이긴 한데 뭔가 할 때마다 헷갈리는 문제.
방금도 헷갈리고 왔다.
dp[i]를 내거를 먹는거라고 봐야 하는 건가 아닌가에 대해 헷갈렸다.
내꺼를 먹는 경우랑 안 먹는 경우 중에 따지는 건데.
1. 내 꺼를 먹고 dp[i-2]값 더한다. i-2번째를 먹었을 수도 안 먹었을 수도 있다.
2. 내거를 안 먹고 dp[i-1] 값을 택한다. i-1번째를 먹었을 수도 안 먹었을 수도 있지만..먹었을 수 있으니까 내 꺼 더하기 안하는 그런거?

문제 해설을 보면 i-1번째를 턴다, i-2번째를 턴다. 그 번쨰를 턴다! 라고 말을 하고 있지만 정작
dp에 담긴 최대값에 대해서 실제로 털었다 안 털었다를 알 수 없는 거 아닌가.
그냥 거기까지 구한 최대 값일 뿐인거지.. 마음에 안드네요.
*/

/*
문)
일직선상의 식량 창고에서 인접한 식량창고를 약탈하지 않고(최소한 한 칸 이상 떨어져 있어야 함)
얻을 수 있는 최대 식량 구하기.
*/

/*
210224 다시 풀면서 느끼는건데..
얘는 d[n-1]을 바로 정답이라고 하잖아.
근데 아닌 애들도 있잖아 다시 max를 찾는..?
그런애들이랑은 어떤 차이가 있다고 말할 수 있는거?
얘는 맨 뒤에 값이 가장 크다고 보장할 수 있다는 이유가 뭐고
다른 문제들에서는 가장 크다고 보장을 못 해서 다시 찾아가는 이유가 뭐임..?
예를 들어서 lis 같은 경우는 다시 찾지 않음?
*/

int n;
int food[101];
int dp[101];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> food[i];
	}

	dp[0] = food[0];
	dp[1] = max(food[1], dp[0]);

	for (int i = 2; i < n; i++) {
		dp[i] = max(food[i] + dp[i - 2], dp[i - 1]);
	}
	cout << dp[n - 1] << endl;

	return 0;
}
