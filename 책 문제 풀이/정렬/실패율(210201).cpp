#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

/*
소숫점 구할 때 어느 한 쪽을 double로 형변환을 해줘야 하는 거였다.
그냥 int형을 바로 쓰니 0만 나옴.
*/

int stageCnt[501];

bool cmp(pair<int, double> a, pair<int, double> b) {
    if(a.second == b.second) {
       return a.first < b.first;
    }
    return a.second > b.second;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    //어떤 번호가 얼마의 실패율을 가지고 있는지 저장한다.
    vector<pair<int, double>> vec;
    
    int n = N;
    int size = stages.size();
    sort(stages.begin(), stages.end());
    
    int cnt=0;
    int val=1;
    int tsize=size;
    for(int i = 0; i < size; i++) {
        stageCnt[stages[i]]++;
    }
    
    int sumVal=0;
    for(int i=1;i<=n;i++) {
        if(size-sumVal!=0){
            vec.push_back({i, (double)stageCnt[i] / (size - sumVal)});
        }
        else vec.push_back({i, 0});
        sumVal += stageCnt[i];
    }
    sort(vec.begin(), vec.end(), cmp);
    for(int i=0;i<n;i++) {
        answer.push_back(vec[i].first);
    }
    
    return answer;
}
