#include<cstdio>
#include<stdio.h>
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>

using namespace std;

//행성 터널
/*
* 거리가 주어진 게 아니었던 문제. 그래서 각 노드사이의 거리를 구해야했는데
* n이 너무 커서 n(n-1)/2로 하기에는 너무 크다.
* 주어진 조건이 |x1- x2| 이런 걸로 하는거라서 밑에처럼 거리를 정할 수 있는 거였다.
* 근데 혼자 생각할 수 있을지는 모르겠다. 이해는 했는데.
*/

int n;
int parent[100000];
vector<pair<int, int>> vecx;
vector<pair<int, int>> vecy;
vector<pair<int, int>> vecz;
vector<pair<int, pair<int, int>>> edges;

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

    cin >> n;
    for (int i = 0; i < n; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        vecx.push_back({ x, i });
        vecy.push_back({ y, i });
        vecz.push_back({ z, i });
    }

    for (int i = 0; i < n; i++) {
        parent[i] = i;
    }

    //이걸 개별로 저장하고 정렬해서
    sort(vecx.begin(), vecx.end());
    sort(vecy.begin(), vecy.end());
    sort(vecz.begin(), vecz.end());

    //인접한 두 개 사이의 간격만 보도록 함. 모두 할 필요는 없다.. 어차피 더 멀어질 뿐이라서.
    for (int i = 0; i < n - 1; i++) {
        edges.push_back({ vecx[i + 1].first - vecx[i].first, {vecx[i].second, vecx[i + 1].second} });
        edges.push_back({ vecy[i + 1].first - vecy[i].first, {vecy[i].second, vecy[i + 1].second} });
        edges.push_back({ vecz[i + 1].first - vecz[i].first, {vecz[i].second, vecz[i + 1].second} });
    }

    //이 밑부터는 동일
    sort(edges.begin(), edges.end());

    int answer = 0;
    for (int i = 0; i < edges.size(); i++) {
        int cost = edges[i].first;
        int n1 = edges[i].second.first;
        int n2 = edges[i].second.second;

        if (findParent(n1) != findParent(n2)) {
            unionParent(n1, n2);
            answer += cost;
        }
    }

    cout << answer << '\n';

    return 0;
}
