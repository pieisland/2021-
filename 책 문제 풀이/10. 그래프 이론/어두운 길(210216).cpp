#include<cstdio>
#include<stdio.h>
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>

using namespace std;

/*
크루스칼 알고리즘으로 푸는 문제. 최소비용신장트리?
최소연결비용을 구하고 전체 비용에서 빼주면 된다.

기억이 하나도 안나서.. 다시 공부했다.
크루스칼 알고리즘은 그리디로 비용을 정렬하고 다른 부모일 때 합쳐나간다.
union find와 함께 사용한다.

신장트리- 하나의 그래프가 있을 때 모든 노드를 포함하면서 사이클이 존재하지 않는 부분 그래프.

벡터 정렬하는 방법을 한 지 오래되어 까먹었음..
begin(), end()를 사용한다.
*/

//어두운 길
int n, m; //집 수, 도로 수 
int parent[200000];
vector<pair<int, pair<int, int>>> vec;

int findParent(int x) {
    if (x == parent[x]) return x;
    return parent[x] = findParent(parent[x]);
}

void unionParent(int x, int y) {
    x = findParent(x);
    y = findParent(y);
    if (x < y) parent[y] = x;
    else parent[x] = y;
}

int main(void) {

    int costSum = 0;

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        vec.push_back({ z, {x, y} });

        costSum += z;
    }

    for (int i = 0; i < n; i++) {
        parent[i] = i;
    }

    //정답이 절약할 수 있는 최대 금액이니까, 전체 금액에서 최소연결비용을 빼면 된다.
    sort(vec.begin(), vec.end());

    int connectVal = 0;
    for (int i = 0; i < m; i++) {
       int n1 = vec[i].second.first;
       int n2 = vec[i].second.second;

       if (findParent(n1) != findParent(n2)) {
           unionParent(n1, n2);
           connectVal += vec[i].first;
       }
    }

    cout << costSum - connectVal << '\n';

    return 0;
}
