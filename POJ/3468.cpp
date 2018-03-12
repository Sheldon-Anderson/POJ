#include<iostream>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

#define LL long long
const int MAX_N = 100005;

// Binary Indexed Tree (BIT)
LL bit1[MAX_N], bit2[MAX_N], sumA[MAX_N];
int A[MAX_N];
int N, Q;

// get sum from index 1 to index i
LL sum(LL *array, int i){
	LL s = 0;
	while(i > 0){
		s += array[i];
		i -= i & -i;
	}
	return s;
}

// add x to index i
void add(LL *array, int i, int x){
	while(i <= N){
		array[i] += x;
		i += i & -i;
	}
}

int main(){
	// cout << log(100000) / log(2) <<endl;
	char ch;
	int a, b, c;
	scanf("%d %d", &N, &Q);
	sumA[0] = 0;
	memset(bit1, 0, sizeof(LL) * (N + 1));
	memset(bit2, 0, sizeof(LL) * (N + 1));
	for(int i = 1; i <= N; i++){
		scanf("%d", &A[i]);
	}
	// get sum of A
	for(int i = 1; i <= N; i++){
		sumA[i] = sumA[i - 1] + A[i];
	}
	// debug
	// cout << "N: " << N << ", Q: " << Q << endl;
	// updates and queries
	for(int i = 1; i <= Q; i++){
		getchar();
		LL ans = 0;
		ch = getchar();
		if(ch == 'Q'){
			scanf("%d %d", &a, &b);
			ans += (sumA[b] + (b + 1) * sum(bit1, b) - sum(bit2, b));
			ans -= (sumA[a - 1] + a * sum(bit1, a - 1) - sum(bit2, a - 1));
			printf("%lld\n", ans);
		}
		else if(ch == 'C'){
			scanf("%d %d %d", &a, &b, &c);
			add(bit1, a, c);
			add(bit1, b + 1, -c);
			add(bit2, a, a * c);
			add(bit2, b + 1, -(b + 1) * c);
		}
	}
	return 0;
}
