#include<cstdio>
#include<stdio.h>
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>

using namespace std;

/*
하다 말아서 날짜 안 적음.
*/

typedef struct Point {
	int y;
	int x;
};

int dir[4][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };

vector<vector<int>> newBoard;

vector<pair<Point, Point>> getNextPos(Point p1, Point p2) {
	vector<pair<Point, Point>> ret;
	
	for (int i = 0; i < 4; i++) {
		Point np1, np2;
		//int np1y, np1x, np2y, np2x;
		np1.y = p1.y + dir[i][0];
		np1.x = p1.x + dir[i][1];
		np2.y = p2.y + dir[i][0];
		np2.x = p2.x + dir[i][1];
	
		if (newBoard[np1.y][np1.x] == 0 && newBoard[np2.y][np2.x] == 0) {
			ret.push_back({ np1, np2 });
		}		
	}

	//가로로 누워있음
	int diff[2] = { 1, -1 };
	if (p1.y == p2.y) {
		for (int i = 0; i < 2; i++) {
			Point np1, np2;
			np1.y = p1.y + diff[i];
			np1.x = p1.x;
			np2.y = p2.y + diff[i];
			np2.x = p2.x;
			if (newBoard[np1.y][np1.x] ==0 && newBoard[np2.y][np2.x]==0) {
				ret.push_back({ np1, np2 });
			}
		}
	}
	else if (p1.x == p2.x) {//세로
		for (int i = 0; i < 2; i++) {
			Point np1, np2;
			np1.y = p1.y;
			np1.x = p1.x + diff[i];
			np2.y = p2.y;
			np2.x = p2.x + diff[i];
			if (newBoard[np1.y][np1.x] == 0 && newBoard[np2.y][np2.x] == 0) {
				ret.push_back({ np1, np2 });
			}
		}
	}

	return ret;
}

int solution(vector<vector<int>> board) {
	int n = board.size();

	newBoard.resize(n+2);
	for (int i = 0; i < n + 2; i++) {
		newBoard[i].resize(n + 2);
	}

	for (int i = 0; i < n + 2; i++) {
		for (int j = 0; j < n + 2; j++) {
			if (i == 0 || i == n + 1 || j == 0 || j == n + 1) {
				newBoard[i][j] = 1;
			}
			else
				newBoard[i][j] = board[i - 1][j - 1];
		}
	}
	
	queue<pair<pair<Point, Point>, int>> q;
	vector<pair<Point, Point>> visited;
	Point p1, p2;
	p1.y = 1;
	p1.x = 1;
	p2.y = 1;
	p2.x = 2;
	q.push({ {p1, p2}, 0 });
	//visit에 대한 처리가 제일.. 문제인뎅..;
	visited.push_back({ p1, p2 });

	while (!q.empty()) {
		Point p1 = q.front().first.first;
		Point p2 = q.front().first.second;
		int cost = q.front().second;
		q.pop();

		if ((p1.y == n && p1.x == n) || (p2.y == n && p2.x == n)) {
			return cost;
		}

		vector<pair<Point, Point>> nextPositions = getNextPos(p1, p2);
		for (int i = 0; i < nextPositions.size(); i++) {
			nextPositions[i].first;
			nextPositions[i].second;

			///.... visited에 있다 없다를 해서.... 있으면 queue에 
		}
		
	}

}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	return 0;
}
