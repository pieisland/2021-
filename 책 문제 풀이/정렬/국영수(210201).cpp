#include<cstdio>
#include<stdio.h>
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>

using namespace std;

int n;
typedef struct Student {
	string name;
	int kor;
	int eng;
	int math;
};

vector<Student> stu;

/*
조건
국어 점수가 감소하는 순서로
국어 점수가 같으면 영어 점수가 증가하는 순서로
국어 점수와 영어 점수가 같으면 수학 점수가 감소하는 순서로
모든 점수가 같으면 이름이 사전 순으로 증가하는 순서로 (단, 아스키 코드에서 대문자는 소문자보다 작으므로 사전순으로 앞에 온다.)

구조체 값 넣을 때 {}로 넣으면 쉽게 넣을 수 있다.
*/

//쓰여진 대로 하고싶었는데 그건 불가능한건가.
//그리고 크기를 비교할 게 아니라.... 
// a <b 이게 증가순이고 a>b 이게 감소순인 듯.
// 아직도 헷갈리고 있다..
bool cmp(Student a, Student b) {
	if (a.kor == b.kor && a.eng == b.eng && a.math == b.math) return a.name < b.name;
	if (a.kor == b.kor && a.eng == b.eng) return a.math > b.math;
	if (a.kor == b.kor) return a.eng < b.eng;
	return a.kor > b.kor;

	/*
  //틀림
	if (a.kor < b.kor) {
		return a.kor > b.kor;
	}
	else if (a.kor == b.kor) {
		return a.eng < b.eng;
	}
	else if (a.kor == b.kor && a.eng == b.eng) {
		return a.math > b.math;
	}
	else if(a.kor == b.kor && a.eng == b.eng && a.math == b.math){
		return a.name < b.name;
	}*/
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		string str;
		int kor, eng, math;
		cin >> str >> kor >> eng >> math;
		Student st = {str, kor, eng, math};
		stu.push_back(st);
	}

	sort(stu.begin(), stu.end(), cmp);

	for (int i = 0; i < n; i++) {
		cout << stu[i].name << '\n';
	}

	return 0;
}
