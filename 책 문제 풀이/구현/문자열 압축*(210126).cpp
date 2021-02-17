#include <string>
#include <vector>

using namespace std;
/*
이 문제에서 얻어갈 것은 문자열 다루는 방법.
substr을 쓰면 전체 문자열에서 원하는 곳부터 원하는 개수만큼
sub 문자열을 구할 수 있다.
안 쓴지 오래돼서 까먹었었다.

솔직히 이런 문제가 다른 문제보다 더 짜증나는 것 같다.
인덱스 실수하기 딱 좋은 문제다.
개수랑 인덱스랑 또 헷갈리면서 틀리기 좋은 문제.
애초에 구현 자체도 결과를 보면 어렵지는 않지만
막상 내가 짜려고 하면 어려움.
*/

int solution(string s) {
	int len = s.size();

	//초기 정답을 길이로 잡는다.
	int ans = len;

	//문자열의 반의 길이만큼만 확인.
	for (int step = 1; step <= len / 2; step++) {
		string compressed = "";//압축 문자열
		string prev = s.substr(0, step);//이전..
		int cnt = 1;//몇 개를 압축할 수 있는가.

		//이 부분을 생각할 수 있어야 한다는 거... step부터 step씩 건너뛰면서 구하는거..
		//step부터인 이유는 인덱스를 0부터 시작하기 때문이다.
		for (int j = step; j < len; j += step) {
			if (prev==s.substr(j, step)) {//같으면 몇 번이나 중복되는지 센다.
				cnt++;
			}
			else {//다르면 센 개수 반영해 압축한다.
				if (cnt == 1) compressed += prev;
				else compressed += to_string(cnt) + prev;
				//다음 값 넣어주고 개수 초기화.
				prev = s.substr(j, step);
				cnt=1;
			}
		}
		if (cnt == 1) compressed += prev;
		else compressed += to_string(cnt) + prev;
		ans = ans < compressed.length() ? ans : compressed.length();
	}

	return ans;
}
