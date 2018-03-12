#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<string>
#include<set>
#include<map>
#include<algorithm>
#include<queue>

using namespace std;

const int MAX_N = 1005;
int N;
int s[MAX_N], e[MAX_N];
pair<int, int> p[MAX_N];

// Interval Scheduling
int main() {
	while (scanf("%d", &N) && N) {
		for (int i = 0; i <= N - 1; i++) {
			scanf("%d", &s[i]);
		}
		for (int i = 0; i <= N - 1; i++) {
			scanf("%d", &e[i]);
		}
		for (int i = 0; i <= N - 1; i++) {
			p[i].first = e[i];
			p[i].second = s[i];
		}
		sort(p, p + N);
		int ans = 0, pre = 0;
		for (int i = 0; i <= N - 1; i++) {
			if (pre < p[i].second) {
				ans++;
				pre = p[i].first;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
