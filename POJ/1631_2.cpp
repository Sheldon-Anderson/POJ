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
	DP: LIS Algorithm 2
	T(n) = O(nlogn)
	Result: Accepted
*/

int LIS_2() {
	memset(dp, 0, sizeof(int) * p);
	int len = 1;
	dp[0] = a[0];
	for (int i = 0; i <= p - 1; i++) {
		int pos = lower_bound(dp, dp + len, a[i]) - dp;
		dp[pos] = a[i];
		len = max(len, pos + 1);
	}
	return len;
}

int main() {
	cin >> n;
	while (n--) {
		cin >> p;
		for (int i = 0; i <= p - 1; i++) {
			cin >> a[i];
		}
		cout << LIS_2() << endl;
	}
	return 0;
}
