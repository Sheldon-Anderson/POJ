#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<string>
#include<set>
#include<map>
#include<algorithm>
#include<queue>
#include<functional>

using namespace std;

char m[25][25];
int W, H, sx, sy, ans, black;
int dir[4][2] = { { 1, 0 },{ 0, -1 },{ -1, 0 },{ 0, 1 } };

// Result: Accepted
void DFS(int sx, int sy) {
	m[sx][sy] = '#';
	ans++;
	for (int i = 0; i <= 3; i++) {
		int tx = sx + dir[i][0];
		int ty = sy + dir[i][1];
		if (tx >= 0 && tx <= H - 1 && ty >= 0 && ty <= W - 1 && m[tx][ty] == '.') {
			DFS(tx, ty);
		}
	}
}

int main() {
	while (cin >> W >> H && W && H) {
		ans = 0;
		black = 0;
		for (int i = 0; i <= H - 1; i++) {
			cin >> m[i];
		}
		for (int i = 0; i <= H - 1; i++) {
			for (int j = 0; j <= W - 1; j++) {
				if (m[i][j] == '@') {
					sx = i;
					sy = j;
				}
				else if (m[i][j] == '.') {
					black++;
				}
			}
		}
		DFS(sx, sy);
		cout << ans << endl;
	}
	return 0;
}