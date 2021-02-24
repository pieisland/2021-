#include<cstdio>
#include<stdio.h>
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>
#include<cmath>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	string s;
	cin >> s;

	bool minusExist = false;
	int value = 0;
	string number = "";

	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '-') {
			int tmpVal = stoi(number);

			if (minusExist) value -= tmpVal;
			else value += tmpVal;
			//그 뒤 숫자들은 전부 빼준다.
			minusExist = true;
			number = "";
		}
		else if (s[i] == '+') {
			int tmpVal = stoi(number);

			if (minusExist) value -= tmpVal;
			else value += tmpVal;
			number = "";
		}
		else {
			//숫자
			number += s[i];
		}
	}

	//마지막에도 해줘야 한다.
	int tmpVal = stoi(number);

	if (minusExist) value -= tmpVal;
	else value += tmpVal;
	
	cout << value;

	//근데 너무 중복되게 짰다.

	return 0;
}
