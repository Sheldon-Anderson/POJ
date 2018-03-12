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

char a[1005], b[1005];
short dp[1005][1005];

int main() {
	// getline(cin, str)
	while (cin >> a >> b) {
		memset(dp, 0, sizeof(dp));
		int la = strlen(a);
		int lb = strlen(b);
		for (int i = 0; i <= la - 1; i++) {
			for (int j = 0; j <= lb - 1; j++) {
				if (a[i] == b[j]) {
					dp[i + 1][j + 1] = dp[i][j] + 1;
				}
				else {
					dp[i + 1][j + 1] = max(dp[i + 1][j], dp[i][j + 1]);
				}
			}
		}
		cout << dp[la][lb] << endl;
	}
	return 0;
}
