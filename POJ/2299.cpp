#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

#define LL long long
const int MAX_N = 500005;

int bit[MAX_N];
int a[MAX_N];
int N;
struct data{
	int index;
	int weight;
}d[MAX_N];

// compare function
int cmp(data a, data b){
	return a.weight < b.weight;
}

// get sum from index 1 to index i
int sum(int i){
	int s = 0;
	while(i > 0){
		s += bit[i];
		i -= i & -i;
	}
	return s;
}

// add x to index i
void add(int i, int x){
	while(i <= N){
		bit[i] += x;
		i += i & -i;
	}
}

int main(){
	while(~scanf("%d", &N) && N != 0){
		memset(bit, 0, sizeof(int) * (N + 1));
		for(int i = 1; i <= N; i++){
			scanf("%d", &d[i].weight);
			d[i].index = i;
		}
		sort(d + 1, d + 1 + N, cmp);
		for(int i = 1; i <= N; i++){
			a[d[i].index] = i;
		}
		// test
		// for(int i = 1; i <= N; i++){
			// cout << a[i] << " ";
		// }
		// cout << endl;
		LL ans = 0;
		for(int i = 1; i <= N; i++){
			add(a[i], 1);
			ans += (i - sum(a[i]));
			// test
			// cout << "i: " << i << ", delta: " << (i - sum(a[i])) << endl;
		}
		printf("%lld\n", ans);
	}
	return 0;
}
