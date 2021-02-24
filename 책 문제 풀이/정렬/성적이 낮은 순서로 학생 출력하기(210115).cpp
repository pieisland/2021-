#include<cstdio>
#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
#include<queue>
using namespace std;

//vector.resize 썼다가 시간 날려먹었다.
//resize할 때랑 그냥 넣어줄 때랑 구분해야 한다.

int n;

vector<pair<int, string>> vec;
vector<pair<int, int>> vec2;
vector<string> strvec;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		string str;
		int score;
		cin >> str >> score;
		vec.push_back({ score, str });
	}

	sort(vec.begin(), vec.end());

	for (int i = 0; i < n; i++) {
		cout << vec[i].second << ' ';
	}

	return 0;
}

/*
2102224
struct 사용한 풀이.

#include<cstdio>
#include<stdio.h>
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>
#include<cmath>

using namespace std;

구조체로 정렬 작성을 했더니 문제가 발생했다.
찾아보니까 구조체 정렬을 할 때는 일반적인 배열처럼 쓸 수 있는 게 아니라
꼭 cmp 하는 함수를 만들어줘야 하는 것 같다.
https://twpower.github.io/71-use-sort-and-stable_sort-in-cpp

이럴바에는 그냥 vector<pair<int, string>> 하는 게 훨씬 편하겠다 싶다.
걔는 맨 처음에 쓴 거를 기준으로 정렬한다.
int 기준으로 기본적으로는 오름차순 정렬을 하게 될 것이다.

int n;
typedef struct Student {
	int grade;
	string name;
} Student;

Student student[100000];

bool cmp(Student a, Student b) {
	return a.grade < b.grade;
}

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		int grade;
		string name;
		cin >> name >> grade;
		student[i] = { grade, name };
	}

	sort(student, student + n, cmp);
	for (int i = 0; i < n; i++) {
		cout << student[i].name << ' ';
	}

	return 0;
}
*/
