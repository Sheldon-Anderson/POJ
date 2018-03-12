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

int n, p;
int a[40005], dp[40005];

/*
DP: LIS Algorithm 1
T(n) = O(n^2)
Result: Time Limit Exceeded
*/

int LIS_1() {
	int ans = 0;
	for (int i = 0; i <= p - 1; i++) {
		dp[i] = 1;
		for (int j = 0; j <= i - 1; j++) {
			if (a[j] < a[i]) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
	}
	ans = 0;
	for (int i = 0; i <= p - 1; i++) {
		if (dp[i] > ans) {
			ans = dp[i];
		}
	}
	return ans;
}

int main() {
	cin >> n;
	while (n--) {
		cin >> p;
		for (int i = 0; i <= p - 1; i++) {
			cin >> a[i];
		}
		cout << LIS_1() << endl;
	}
	return 0;
}
