#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<string>
#include<set>
#include<map>
#include<queue>
#include<algorithm>

using namespace std;

int M, X, Y, T;
int m[305][305];
int dx[] = {0, 1, 0, -1, 0 };
int dy[] = {0, 0, -1, 0, 1 };
struct Node {
	int x, y, time;
	Node(int x, int y, int time) : x(x), y(y), time(time) {}
};

int BFS(Node node) {
	queue<Node> q;
	while (!q.empty()) {
		q.pop();
	}
	if (m[node.x][node.y] == -1) {
		return node.time;
	}
	else if (m[node.x][node.y] == 0) {
		return -1;
	}
	else {
		q.push(node);
		m[node.x][node.y] = -2;
	}
	while (!q.empty()) {
		Node t = q.front();
		q.pop();
		for (int i = 1; i <= 4; i++) {
			Node tt = t;
			tt.x += dx[i];
			tt.y += dy[i];
			tt.time += 1;
			if(tt.x >= 0 && tt.x <= 302 && tt.y >= 0 && tt.y <= 302 && (m[tt.x][tt.y] == -1 || tt.time < m[tt.x][tt.y])){
				if(m[tt.x][tt.y] == -1){
					return tt.time;
				}
				else{
					q.push(tt);
					m[tt.x][tt.y] = -2;
				}
			}
		}
	}
	return -1;
}

int main() {
	memset(m, -1, sizeof(m));
	scanf("%d", &M);
	for (int i = 0; i <= M - 1; i++) {
		scanf("%d %d %d", &X, &Y, &T);
		/*
			m[X][Y] = T;
			In this way, it caused an error!
		*/
		for (int j = 0; j <= 4; j++) {
			int tX = X + dx[j], tY = Y + dy[j];
			if (tX >= 0 && tX <= 301 && tY >= 0 && tY <= 301 && (m[tX][tY] == -1 || T < m[tX][tY])) {
				m[tX][tY] = T;
			}
		}
	}
	printf("%d\n", BFS(Node(0, 0, 0)));
	return 0;
}
