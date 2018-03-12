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

int w, h, sx, sy, ex, ey, ans;
int m[25][25];
int dir[4][2] = { { 1, 0 },{ 0, -1 },{ -1, 0 },{ 0, 1 } };

void DFS(int sx, int sy, int cnt) {
	if (sx == ex && sy == ey && cnt <= 10) {
		ans = min(ans, cnt);
		return;
	}
	if (cnt > 10) {
		return;
	}
	for (int i = 0; i <= 3; i++) {
		int tx = sx + dir[i][0];
		int ty = sy + dir[i][1];
		while (tx >= 0 && tx <= h - 1 && ty >= 0 && ty <= w - 1) {
			if (tx == ex && ty == ey) {
				DFS(tx, ty, cnt + 1);
				break;
			}
			else if (m[tx][ty] == 1) {
				if (!(sx == tx - dir[i][0] && sy == ty - dir[i][1])) {
					m[tx][ty] = 0;
					DFS(tx - dir[i][0], ty - dir[i][1], cnt + 1);
					m[tx][ty] = 1;
				}
				break;
			}
			tx += dir[i][0];
			ty += dir[i][1];
		}
	}
	return;
}

int main() {
	while (cin >> w >> h && w && h) {
		for (int i = 0; i <= h - 1; i++) {
			for (int j = 0; j <= w - 1; j++) {
				cin >> m[i][j];
				if (m[i][j] == 2) {
					sx = i;
					sy = j;
				}
				else if (m[i][j] == 3) {
					ex = i;
					ey = j;
				}
			}
		}
		ans = 1 << 30;
		DFS(sx, sy, 0);
		if (ans == 1 << 30) {
			cout << -1 << endl;
		}
		else {
			cout << ans << endl;
		}
	}
	return 0;
}
