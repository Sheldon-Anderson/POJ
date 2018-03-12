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
// int dp[5001][5001];
/*
	Result: Memory Limit Exceeded
*/
short dp[5005][5005];
char a[5005];
// char b[5005];

/*
	DP: LCS Algorithm 1
	T(N) = O(N^2)
	Result:	Accepted
*/

short LCS_1() {
	memset(dp, 0, sizeof(dp));
	for (int i = 0; i <= N - 1; i++) {
		for (int j = 0; j <= N - 1; j++) {
			if (a[i] == a[N - 1 - j]) {
				dp[i + 1][j + 1] = dp[i][j] + 1;
			}
			else {
				dp[i + 1][j + 1] = max(dp[i + 1][j], dp[i][j + 1]);
			}
		}
	}
	return dp[N][N];
}

int main() {
	cin >> N;
	cin >> a;
	//for (int i = 0; i <= N - 1; i++) {
	//	b[i] = a[N - 1 - i];
	//}
	cout << N - LCS_1() << endl;
	return 0;
}
