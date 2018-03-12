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
int a[20005];
long long ans;
priority_queue<long long, vector<long long>, greater<long long>> q;  // increase

int main() {
	cin >> n;
	ans = 0;
	for(int i = 0; i <= n - 1; i++){
		cin >> a[i];
		q.push(a[i]);
	}
	while(q.size() >= 2){
		long long t1 = q.top();
		q.pop();
		long long t2 = q.top();
		q.pop();
		ans += t1 + t2;
		q.push(ans);
	}
	cout << ans;
	return 0;
}
