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

bool maze[25][25];
// _,_ _,_ _,_ _,_ _,_ _,_ _,_: 00, 01, 10, 11 means 4 diffierent directions
// bool vis[25][25][1 << 14];
int d[10];
int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, -1, 0, 1 };
int vis[25][25][1 << 14];
int n, m, L, K;
int cnt = 0;
struct Node {
	int x, y, dir, step;
	Node(int x, int y, int dir, int step) : x(x), y(y), dir(dir), step(step) {}
};

bool check(int tx, int ty, Node t) {
	for (int i = L - 1; i >= 1; i--) {
		d[i] = t.dir & 3;
		t.dir >>= 2;
	}
	int nx = t.x, ny = t.y;
	for (int i = 1; i <= L - 1; i++) {
		nx += dx[d[i]];
		ny += dy[d[i]];
		if (tx == nx && ty == ny) {
			return true;
		}
	}
	return false;
}

int BFS(Node node) {
	queue<Node> q;
	while (!q.empty()) {
		q.pop();
	}
	q.push(node);
	vis[node.x][node.y][node.dir] = cnt;
	while (!q.empty()) {
		Node t = q.front();
		q.pop();
		if (t.x == 1 && t.y == 1) {
			return t.step;
		}
		for (int i = 0; i <= 3; i++) {
			int tx = t.x + dx[i], ty = t.y + dy[i];
			if (tx < 1 || tx > n || ty < 1 || ty > m || maze[tx][ty] || check(tx, ty, t)) {
				continue;
			}
			int tdir = (t.dir >> 2) + (((i + 2) % 4) << (2 * (L - 2)));
			int tstep = t.step + 1;
			if (vis[tx][ty][tdir] == cnt) {
				continue;
			}
			q.push(Node(tx, ty, tdir, tstep));
			vis[tx][ty][tdir] = cnt;
		}
	}
	return -1;
}

// C++ caused a Time Limit Exceeded
// G++ get an Accepted
int main() {
	while (scanf("%d %d %d", &n, &m, &L) && n && m && L) {
		memset(maze, false, sizeof(maze));
		// memset(vis, false, sizeof(vis));
		cnt++;
		int px = -1, py = -1, tx, ty;
		Node node(0, 0, 0, 0);
		for (int i = 0; i <= L - 1; i++) {
			scanf("%d %d", &tx, &ty);
			if (px == -1 && py == -1) {
				node.x = tx;
				node.y = ty;
			}
			else {
				for (int j = 0; j <= 3; j++) {
					if (tx == px + dx[j] && ty == py + dy[j]) {
						node.dir = (node.dir << 2) + j;
						break;
					}
				}
			}
			px = tx;
			py = ty;
		}
		scanf("%d", &K);
		int sx, sy;
		for (int i = 0; i <= K - 1; i++) {
			scanf("%d %d", &sx, &sy);
			maze[sx][sy] = 1;
		}
		printf("Case %d: %d\n", cnt, BFS(node));
	}
	return 0;
}
