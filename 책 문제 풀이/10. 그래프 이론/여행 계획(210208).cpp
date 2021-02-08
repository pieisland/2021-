#include<cstdio>
#include<stdio.h>
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>

using namespace std;

/*
여행계획.
언제 부모를 합치는건가 했더니만 그냥 바로 1일 때 합쳐버리네.

그리고 해설을 봤는데, 이미 unionParent를 할 때 부모를 다 구하는 거 아닌가..?
왜 마지막에 또 findParent 해가지고 부모 비교하는지 모르겠음.
*/

int n, m;
int parent[501];

//그리고 parent[a]에 대입해줘야하는 거 잊었었다.
int getParent(int a) {
    if (a == parent[a]) {
        return a;
    }
    else return parent[a] = getParent(parent[a]);
}

void unionParent(int a, int b) {
    a = getParent(a);
    b = getParent(b);

    if (a < b) {
        parent[b] = a;
    }
    else {
        parent[a] = b;
    }
}

int main(void) {

    cin >> n >> m;

    for (int i = 1; i <= n; i++) parent[i] = 1;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++) {
            int x;
            cin >> x;

            if (x == 1) unionParent(i + 1, j + 1);
        }
    }

    vector<int> city;
    city.resize(m);
    for (int i = 0; i < m; i++) {
        cin >> city[i];
    }

    int tmpParent = parent[city[0]];
    bool answer = true;
    for (int i = 1; i < m; i++) {
        if (parent[city[i]] != tmpParent) {
            answer = false;
            break;
        }
    }

    if (answer) {
        cout << "YES" << '\n';
    }
    else cout << "NO" << '\n';

    return 0;
}
