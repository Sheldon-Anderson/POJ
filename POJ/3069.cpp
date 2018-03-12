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

int R, n, ans;
int a[1005];

// greedy algorithm
int main() {
	while (cin >> R >> n && R != -1 && n != -1) {
		ans = 0;
		for (int i = 0; i <= n - 1; i++) {
			cin >> a[i];
		}
		sort(a, a + n);
		int s = 0;
		while (s <= n - 1) {
			if (s == n - 1) {
				ans++;
				break;
			}
			int d1 = a[s] + R;
			int e = s + 1;
			for (; e <= n - 1; e++) {
				if (a[e] > d1) {
					break;
				}
			}
			ans++;
			if (e <= n - 1) {
				int d2 = a[e - 1] + R;
				int t = e;
				for (; t <= n - 1; t++) {
					if (a[t] > d2) {
						break;
					}
				}
				if (t <= n - 1) {
					s = t;
				}
				else {
					break;
				}
			}
			else {
				break;
			}
		}
		cout << ans << endl;
	}
	return 0;
}
