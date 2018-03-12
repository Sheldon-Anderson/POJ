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

string tmp;
string a[105], b[105], ans[105];
short dp[105][105];
int la = 0, lb = 0, len, cnt = 0;
bool flag = false;

void LCS() {
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
}

// Result: Accepted
void DFS(int l_a, int l_b, int l_lcs) {
	if (l_a <= 0 || l_b <= 0 || l_lcs <= 0) {
		flag = true;
		return;
	}
	// if we don't use flag, we would get a Result: Time Limit Exceeded
	if (flag) {
		return;
	}
	if (a[l_a - 1] == b[l_b - 1]) {
		ans[l_lcs - 1] = a[l_a - 1];
		DFS(l_a - 1, l_b - 1, l_lcs - 1);
	}
	else {
		if (dp[l_a - 1][l_b] >= dp[l_a][l_b - 1]) {
			DFS(l_a - 1, l_b, l_lcs);
		}
		if (dp[l_a][l_b - 1] >= dp[l_a - 1][l_b]) {
			DFS(l_a, l_b - 1, l_lcs);
		}
	}
}

int main() {
	while (cin >> tmp) {
		if (tmp == "#") {
			cnt = (cnt + 1) % 2;
			if (cnt == 0) {
				LCS();
				len = dp[la][lb];
				DFS(la, lb, len);
				cout << ans[0];
				if (len > 1) {
					for (int i = 1; i <= len - 1; i++) {
						cout << " " << ans[i];
					}
				}
				cout << endl;
				la = lb = len = 0;
				flag = false;
			}
		}
		else {
			if (cnt == 0) {
				a[la++] = tmp;
			}
			else {
				b[lb++] = tmp;
			}
		}
	}
	return 0;
}