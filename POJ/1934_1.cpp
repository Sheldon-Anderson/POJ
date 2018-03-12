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

char A[85], B[85], tmp[85];
short dp[85][85], last_1[85][35], last_2[85][35];
int la, lb, len;
set<string> ans;
set<string>::iterator ite;

void LCS() {
	memset(dp, 0, sizeof(dp));
	for (int i = 0; i <= la - 1; i++) {
		for (int j = 0; j <= lb - 1; j++) {
			if (A[i] == B[j]) {
				dp[i + 1][j + 1] = dp[i][j] + 1;
			}
			else {
				dp[i + 1][j + 1] = max(dp[i + 1][j], dp[i][j + 1]);
			}
		}
	}
}

// Result: Accepted
void printAllLcsPaths(int la, int lb, int len) {
	if (len <= 0) {
		ans.insert(tmp);
		return;
	}
	if (la < 0 || lb < 0) {
		return;
	}
	for (int i = 0; i <= 25; i++) {
		int p1 = last_1[la][i];
		int p2 = last_2[lb][i];
		if (p1 != -1 && p2 != -1 && dp[p1 + 1][p2 + 1] == len) {
			tmp[len - 1] = 'a' + i;
			// printAllLcsPaths(p1, p2, len - 1);
			printAllLcsPaths(p1 - 1, p2 - 1, len - 1);
		}
	}
}

int main() {
	cin >> A >> B;
	la = strlen(A);
	lb = strlen(B);
	LCS();
	len = dp[la][lb];
	memset(last_1, 0, sizeof(last_1));
	memset(last_2, 0, sizeof(last_2));
	for (int i = 0; i <= la - 1; i++) {
		for (int j = 0; j <= 25; j++) {
			if (A[i] == 'a' + j) {
				last_1[i][j] = i;
			}
			else {
				last_1[i][j] = i == 0 ? -1 : last_1[i - 1][j];
			}
		}
	}
	for (int i = 0; i <= lb - 1; i++) {
		for (int j = 0; j <= 25; j++) {
			if (B[i] == 'a' + j) {
				last_2[i][j] = i;
			}
			else {
				last_2[i][j] = i == 0 ? -1 : last_2[i - 1][j];
			}
		}
	}
	memset(tmp, 0, sizeof(tmp));
	printAllLcsPaths(la - 1, lb - 1, len);
	for (ite = ans.begin(); ite != ans.end(); ite++) {
		cout << (*ite) << endl;
	}
	return 0;
}
