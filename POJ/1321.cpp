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

int n, k, ans, sx, sy;
// int dir[4][2] = { { 1, 0 },{ 0, -1 },{ -1, 0 },{ 0, 1 } };
char m[10][10];
bool cols[10];

// Result: Accepted
void DFS(int row, int cnt) {
	if (cnt == k) {
		ans++;
		return;
	}
	if (row + 1 <= n - 1) {
		DFS(row + 1, cnt);
		for (int j = 0; j <= n - 1; j++) {
			if (row + 1 <= n - 1 && m[row + 1][j] == '#' && cols[j] == false) {
				cols[j] = true;
				DFS(row + 1, cnt + 1);
				cols[j] = false;
			}
		}
	}
}

int main() {
	while (cin >> n >> k && n != -1 && k != -1) {
		for (int i = 0; i <= n - 1; i++) {
			cin >> m[i];
		}
		memset(cols, 0, sizeof(cols));
		ans = 0;
		DFS(-1, 0);
		cout << ans << endl;
	}
	return 0;
}
