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

char A[85], B[85];
short dp[85][85];
int la, lb;
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

// Result: Time Limit Exceeded
set<string> printAllLcsPaths(int i, int j) {
	set<string> lcsPaths;
	if (i == 0 || j == 0) {
		lcsPaths.insert("");
	}
	else if (A[i - 1] == B[j - 1]) {
		set<string> tmp = printAllLcsPaths(i - 1, j - 1);
		for (ite = tmp.begin(); ite != tmp.end(); ite++) {
			lcsPaths.insert((*ite) + A[i - 1]);
		}
	}
	else {
		if (dp[i - 1][j] >= dp[i][j - 1]) {
			set<string> tmp = printAllLcsPaths(i - 1, j);
			for (ite = tmp.begin(); ite != tmp.end(); ite++) {
				lcsPaths.insert((*ite));
			}
		}
		if (dp[i][j - 1] >= dp[i - 1][j]) {
			set<string> tmp = printAllLcsPaths(i, j - 1);
			for (ite = tmp.begin(); ite != tmp.end(); ite++) {
				lcsPaths.insert((*ite));
			}
		}
	}
	return lcsPaths;
}

int main() {
	cin >> A >> B;
	la = strlen(A);
	lb = strlen(B);
	LCS();
	set<string> ans = printAllLcsPaths(la, lb);
	for (ite = ans.begin(); ite != ans.end(); ite++) {
		cout << (*ite) << endl;
	}
	return 0;
}
