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

int R, C, ans;
short m[105][105];
int dp[105][105];
int dir[4][2] = { { 1, 0 },{ 0, -1 },{ -1, 0 },{ 0, 1 } };
bool vis[105][105];

// memory DFS
void DFS(int x, int y, int cnt) {
	bool flag = false;
	for (int i = 0; i <= 3; i++) {
		int tx = x + dir[i][0];
		int ty = y + dir[i][1];
		if (tx >= 0 && tx <= R - 1 && ty >= 0 && ty <= C - 1 && !vis[tx][ty] && m[tx][ty] < m[x][y]) {
			if (dp[tx][ty] > 0) {
				ans = max(ans, cnt + dp[tx][ty]);
			}
			else {
				flag = true;
				vis[tx][ty] = true;
				DFS(tx, ty, cnt + 1);
				vis[tx][ty] = false;
			}
		}
	}
	if (!flag) {
		ans = max(ans, cnt);
		return;
	}
}

int main() {
	ans = -1;
	memset(dp, 0, sizeof(dp));
	cin >> R >> C;
	for (int i = 0; i <= R - 1; i++) {
		for (int j = 0; j <= C - 1; j++) {
			cin >> m[i][j];
		}
	}
	for (int i = 0; i <= R - 1; i++) {
		for (int j = 0; j <= C - 1; j++) {
			memset(vis, false, sizeof(vis));
			vis[i][j] = true;
			DFS(i, j, 1);
			dp[i][j] = max(dp[i][j], ans);
			// vis[i][j] = false;
		}
	}
	cout << ans << endl;
	return 0;
}
