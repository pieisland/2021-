#include<cstdio>
#include<stdio.h>
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>

using namespace std;

//행성 터널

typedef struct Point {
    int x;
    int y;
    int z;
};

int n;

int parent[100000];
vector<Point> node;
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

    cin >> n;
    for (int i = 0; i < n; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        Point pt = { x, y, z };
        node.push_back(pt);
    }

    for (int i = 0; i < n; i++) {
        parent[i] = i;
    }

    //아니 거리를 내가 뽑아야되는거잖아요.
    //그 다음에 정렬해야될 거고.
    //그러면 n^2은 될텐데. 그렇게 했을 떄 시간초과가 나지 않을까 거리계산하는것 때문에.
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            int diffx = node[i].x - node[j].x;
            if (diffx < 0) diffx = -diffx;
            int diffy = node[i].y - node[j].y;
            if (diffy < 0) diffy = -diffy;
            int diffz = node[i].z - node[j].z;
            if (diffz < 0) diffz = -diffz;

            int diff = min(diffx, min(diffy, diffz));
         
            vec.push_back({ diff, {i, j} });
        }
    }

    sort(vec.begin(), vec.end());

    int answer = 0;
    for (int i = 0; i < vec.size(); i++) {
        int n1 = vec[i].second.first;
        int n2 = vec[i].second.second;
        if (findParent(n1) != findParent(n2)) {
            unionParent(n1, n2);
            answer += vec[i].first;
        }
    }

    cout << answer << endl;

    return 0;
}
