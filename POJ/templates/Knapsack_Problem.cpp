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

const int MAX_N = 105;
const int MAX_W = 10005;

int n, W;
int w[MAX_N], v[MAX_N];
int dp[MAX_W + 1];

// 0 - 1 Knapsack_Problem
void zero_one_Knapsack() {
	memset(dp, 0, sizeof(dp));
	for (int i = 0; i <= n - 1; i++) {
		for (int j = W; j >= w[i]; j--) {
			dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
		}
	}
}

// Full Knapsack_Problem
void full_Knapsack() {
	memset(dp, 0, sizeof(dp));
	for (int i = 0; i <= n - 1; i++) {
		for (int j = w[i]; j <= W; j++) {
			dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
		}
	}
}

// Knapsack Problem
int main() {
	while (cin >> n >> W && n && W) {
		for (int i = 0; i <= n - 1; i++) {
			cin >> w[i];
		}
		for (int i = 0; i <= n - 1; i++) {
			cin >> v[i];
		}
		zero_one_Knapsack();
		cout << "0 - 1 Knapsack_Problem: " << dp[W] << endl;
		full_Knapsack();
		cout << "Full Knapsack_Problem: " << dp[W] << endl;
	}
	return 0;
}
