#include <string>
#include <vector>
#include <iostream>

/*
재귀호출이 핵심..
막상 하면 어렵지는 않은데 문제 읽고 어려워서 하기 싫어지는 문제.

하라는 대로 하면 되기는 한다.
조금 복잡할 뿐..

올바른 문자열인지를 파악하는 걸 스택으로 해결해보았다.
예전에는 +1 -1로 했었는데 어차피 그거나 그거나 동일하다.
+1, -1로 한다면 0이 되는 순간에 인덱스를 저장하고
모든 확인이 끝난 후에 해당 인덱스가 마지막 인덱스라면 true, 아니면 false가 된다.

이게 어차피 findBalance에서 사용한 것과 동일하다.
findBalance에서 다른 점은 0이 되는 순간 해당 인덱스를 바로 반환한다는 것.

u, v를 찾고 어떤 경우든 v는 결국 1번부터 다시 실행해야 하기 때문에 재귀호출해서 다시 구해준다.
그리고 경우에 따라서 더해서 return 해주면 된다.

참고로 substr의 두 번째 인자(몇 개 자를건지)를 안 적으면 시작한 곳부터 끝까지 가져와준다.
*/

using namespace std;

int findBalance(string s) {
	int val = 0;
	int idx = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '(') val += 1;
		else val -= 1;

		if (val == 0)
		{
			idx = i;
			break;
		}
	}

	return idx;
}

bool isRight(string p) {
	vector<int> vec;
	int len = p.size();
	bool check = true;
	for (int i = 0; i < len; i++) {
		if (p[i] == '(') {
			vec.push_back(1);
		}
		else {
			if (vec.size() == 0) {
				check = false;
				break;
			}
			vec.pop_back();
		}
	}
	if (check) {
		return true;
	}
	return false;
}

string cutAndReverseStr(string s) {
	string tmp = "";
	for(int i=1;i<s.size()-1;i++) {
        if(s[i]=='(')
            tmp+=')';
        else tmp+='(';
    }
	return tmp;
}

string func(string p) {
	//빈 문자열이면 바로 리턴한다.
	if (p == "") return p;

	if (isRight(p)) {
		return p;
	}

	//이 밑은 균형은 잡혔는데 올바르지 않은 경우..
	//일단 분리를 해야하는데
	int idx = findBalance(p);
	string u = p.substr(0, idx + 1);
	string v = p.substr(idx + 1);
	
	v = func(v);
	if (isRight(u)) {
		return u + v;
	}
	else {
		return '(' + v + ')' + cutAndReverseStr(u);
	}
}

string solution(string p) {
    string answer = "";
	
	answer = func(p);

	cout << answer << endl;
    return answer;
}
