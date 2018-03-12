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

int C, G;
int l[25];
int w[25];
// [-15 * 25 * 20, 15 * 25 * 20] = [-7500, 7500] (+7500)===> [0, 15000]
int dp[25][15005];

void zero_one_Knapsack() {
	memset(dp, 0, sizeof(dp));
	// init: when we put nothing on, it's in a balanced state
	dp[0][7500] = 1;
	for (int i = 1; i <= G; i++) {
		for (int j = 0; j <= 15000; j++) {
			if (dp[i - 1][j]) {
				for (int k = 0; k <= C - 1; k++) {
					dp[i][j + l[k] * w[i]] += dp[i - 1][j];
				}
			}
		}
	}
}

int main() {
	cin >> C >> G;
	for (int i = 0; i <= C - 1; i++) {
		cin >> l[i];
	}
	for (int i = 1; i <= G; i++) {
		cin >> w[i];
	}
	zero_one_Knapsack();
	cout << dp[G][7500] << endl;
	return 0;
}
