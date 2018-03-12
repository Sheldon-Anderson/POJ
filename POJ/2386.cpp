#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<string>
#include<set>
#include<map>
#include<vector>

using namespace std;

int N, M;
char a[105][105];

void dfs(int i, int j) {
	a[i][j] = '.';
	for (int x = -1; x <= 1; x++) {
		for (int y = -1; y <= 1; y++) {
			if (x == 0 && y == 0) {
				continue;
			}
			if (i + x >= 0 && i + x <= N - 1 && j + y >= 0 && j + y <= M - 1 && a[i + x][j + y] == 'W') {
				dfs(i + x, j + y);
			}
		}
	}
}

int main() {
	scanf("%d %d%*c", &N, &M);
	for (int i = 0; i <= N - 1; i++) {
		scanf("%s", &a[i]);
	}
	int ans = 0;
	for (int i = 0; i <= N - 1; i++) {
		for (int j = 0; j <= M - 1; j++) {
			if (a[i][j] == 'W') {
				dfs(i, j);
				ans++;
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}
