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

int n, d, cnt = 0;
double x, y;
pair<double, double> p[1005];

int main() {
	while (cin >> n >> d && (n || d)) {
		int ans = 0;
		for (int i = 0; i <= n - 1; i++) {
			cin >> x >> y;
			if (n <= 0 || y < 0 || y > d || d < 0) {
				ans = -1;
			}
			p[i].first = x + sqrt(d * d - y * y);		// end
			p[i].second = x - sqrt(d * d - y * y);		// start
		}
		if (ans == 0) {
			// Interval Scheduling
			sort(p, p + n);
			double pre = p[0].second - 1;
			for (int i = 0; i <= n - 1; i++) {
				if (p[i].second > pre) {
					ans++;
					pre = p[i].first;
				}
			}
		}
		cout << "Case " << ++cnt << ": " << ans << endl;
	}
	return 0;
}
