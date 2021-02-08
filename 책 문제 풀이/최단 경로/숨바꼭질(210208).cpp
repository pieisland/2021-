#include<cstdio>
#include<stdio.h>
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>

using namespace std;

using namespace std;

int n, m;
int conn[20001][20001];
int dp[20001];

int minVal = 987654321;
int ansIdx;
int ansDist;
int ansCnt;

void dijkstra() {
    priority_queue<pair<int, int>> q;
    q.push({ 0, 1 });
    dp[1] = 0;

    while (!q.empty()) {
        int cost = -q.top().first;
        int now = q.top().second;
        q.pop();

        for (int i = 1; i <= n; i++) {
            if (conn[now][i] == 0) continue;

            int dist = cost + 1;
            if (dist < dp[i]) {
                dp[i] = dist;
                q.push({ -dist, i });

                /*if (dist < minVal) {
                    minVal = dist;
                    ansIdx = i;
                    ansDist = dist;
                    ansCnt = 1;
                }*/
            }
            /*else if (dist == dp[i]) {
                if (i < ansIdx) ansIdx = i;
                ansCnt += 1;
            }*/
        }
    }
}

int main(void) {
    
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        conn[a][b] = 1;
        conn[b][a] = 1;
    }
   
    for (int i = 1; i <= n; i++) {
        dp[i] = 987654321;
    }

    dijkstra();

    /*for (int i = 1; i <= n; i++) {
        cout << dp[i] << ' ';
    }*/

    for (int i = 1; i <= n; i++) {
        if (dp[i] > ansDist) {
            ansIdx = i;
            ansDist = dp[i];
            ansCnt = 1;
        }
        else if (dp[i] == ansDist) {
            ansCnt++;
        }
    }

    cout << ansIdx << " " << ansDist << ' ' << ansCnt << endl;

    return 0;
}
