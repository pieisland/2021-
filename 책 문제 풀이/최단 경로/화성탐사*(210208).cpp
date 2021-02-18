#include<cstdio>
#include<stdio.h>
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>

using namespace std;

/*
테스트케이스

3
3
5 5 4
3 9 1
3 2 7
5
3 7 2 0 1
2 8 0 9 1
1 2 1 8 1
9 8 9 2 0
3 6 5 1 5 
7
9 0 5 1 1 5 3
4 1 2 1 6 5 3
0 7 6 1 6 8 5
1 1 7 8 3 2 3
9 4 0 7 6 4 1
5 8 3 2 4 8 3
7 4 8 4 8 3 4
*/

/*
정답

20
19
36
*/

/*
이걸 dp로 풀 수 없는 이유는 상하좌우 이동이 가능하기 때문인 듯.
내가 dp로 처음에 풀었던 방식은 오른쪽이나 아래로만 이동하니까.. 제대로 고려가 된 게 아닌거다.
다익스트라. 며칠 지나면 바로 까먹는 다익스트라 구현법.
*/

int INF = 987654321;

/*int t;
int n;
int board[126][126];
int dp[126][126];

void initDp() {
	for (int i = 0; i < 126; i++) {
		for (int j = 0; j < 126; j++) {
			dp[i][j] = 0;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> t;
	for (int test = 0; test < t; test++) {
		cin >> n;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> board[i][j];
			}
		}
		initDp();

		dp[0][0] = board[0][0];
		for (int i = 1; i < n; i++) {
			dp[0][i] = dp[0][i - 1] + board[0][i];
			dp[i][0] = dp[i - 1][0] + board[i][0];
		}

		for (int i = 1; i < n; i++) {
			for (int j = 1; j < n; j++) {
				dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + board[i][j];
			}
		}

		cout << dp[n-1][n-1] << endl;
	}

	return 0;
}
*/

using namespace std;

int testCase, n;
int graph[125][125], d[125][125];
int dir[4][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };

bool isinside(int y, int x) {
    if (y >= 0 && y < n && x >= 0 && x < n) return true;
    else return false;
}

int main(void) {
    cin >> testCase;

    for (int tc = 0; tc < testCase; tc++) {
        cin >> n;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> graph[i][j];
            }
        }

        for (int i = 0; i < n; i++) {
            fill(d[i], d[i] + 125, INF);
        }

        int y = 0, x = 0;
        priority_queue<pair<int, pair<int, int> > > pq;
        pq.push({ -graph[y][x], {0, 0} });
        d[y][x] = graph[y][x];

        while (!pq.empty()) {
            int dist = -pq.top().first;
            int y = pq.top().second.first;
            int x = pq.top().second.second;
            pq.pop();
  
            if (d[y][x] < dist) continue;

            for (int i = 0; i < 4; i++) {
                int ny = y + dir[i][0];
                int nx = x + dir[i][1];

                if (!isinside(y, x)) continue;
                int cost = dist + graph[ny][nx];
                
                if (cost < d[ny][nx]) {
                    d[ny][nx] = cost;
                    pq.push({ -cost, {ny, nx} });
                }
            }
        }
        cout << d[n - 1][n - 1] << '\n';
    }
   
    return 0;
}
