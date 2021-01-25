#include <string>
#include <vector>

using namespace std;

int solution(vector<int> vec, long long k) {
  int ans = 0;
	int foodCnt = 0;
	for (int i = 0; i < vec.size(); i++)
		foodCnt += vec[i];

	int idx = 0;
	int time = 0;
	int eatCnt = 0;
	
	while (1) {
		//먹고 시간 증가.
		if (vec[idx] != 0) {
			vec[idx] -= 1;
			eatCnt++;
			time++;
		}

		//다 먹었으면 언제 끊기든지 더 먹을 음식 없음.
		if (eatCnt == foodCnt) {
			ans = -1;
			break;
		}

		//다음 위치를 찾는다.
		idx++; //간단하게는 1을 더하는데
		if (idx == vec.size()) idx = 0;
		int pos = idx;
		bool check = true;
		while (1) {
			if (vec[idx] == 0) {
				idx++;
				if (idx == vec.size()) idx = 0;
			}
			else {
				break;
			}
			if (pos == idx) { //다시 돌아왔는데 못 찾은 경우(사실 이미 음식 다 먹은 거에서 걸리기 때문에 이 경우는 안 생긴다)
				ans = -1;
				check = false;
				break;
			}
		}
		if (!check) break;

		if (time == k) {
			break;
		}
	}

	if (ans != -1) ans = idx + 1;
	//cout << ans << endl;
	return ans;
}
