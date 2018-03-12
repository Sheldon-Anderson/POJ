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

int N;
char a[5005], b[5005];
vector<short> vec;
vector<short>::iterator it;

/*
	DP: LCS Algorithm 2, transform from LCS to LIS Problem
	T(N) = O(NlogN)
	Result: Memory Limit Exceeded
*/

int LIS_2() {
	short *dp = new short[vec.size()];
	memset(dp, 0, sizeof(dp));
	int len = 1;
	dp[0] = vec[0];
	for (int i = 1; i <= vec.size() - 1; i++) {
		int pos = lower_bound(dp, dp + len, vec[i]) - dp;
		dp[pos] = vec[i];
		len = max(len, pos + 1);
	}
	return len;
}

int main() {
	cin >> N;
	cin >> a;
	for (int i = 0; i <= N - 1; i++) {
		b[i] = a[N - 1 - i];
	}
	for (int i = 0; i <= N - 1; i++) {
		for (int j = N - 1; j >= 0; j--) {
			if (a[i] == b[j]) {
				vec.push_back(j);
			}
		}
	}
	cout << N - LIS_2() << endl;
	return 0;
}
