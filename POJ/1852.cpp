#include<iostream>
#include<cstdio>	
#include<cstring>
#include<cmath>
#include<string>
#include<set>
#include<map>
#include<vector>
#include<algorithm>

using namespace std;

int a[1000005];

int main() {
	int T, L, N;
	scanf("%d%*c", &T);
	for (int i = 1; i <= T; i++) {
		scanf("%d %d", &L, &N);
		for (int j = 0; j <= N - 1; j++) {
			scanf("%d", &a[j]);
		}
		int min_t = 0, max_t = 0;
		for (int j = 0; j <= N - 1; j++) {
			min_t = max(min_t, min(a[j], L - a[j]));
			max_t = max(max_t, max(a[j], L - a[j]));
		}
		printf("%d %d\n", min_t, max_t);
	}
	return 0;
}
