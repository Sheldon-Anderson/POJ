#include<iostream>
#include<cstdio>
#include<cstring>
#include<climits>
#include<algorithm>
using namespace std;

#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1
#define LL long long
const int MAX_N = 100005;

int A[MAX_N];
LL lazy[MAX_N << 2], sum[MAX_N << 2];

void PushUp(int rt){
	sum[rt] = sum[rt << 1] + sum[rt << 1 | 1];
}

void PushDown(int rt, int m){
	if(lazy[rt]){
		lazy[rt << 1] += lazy[rt];
		lazy[rt << 1 | 1] += lazy[rt];
		sum[rt << 1] += (m - (m >> 1)) * lazy[rt];
		sum[rt << 1 | 1] += (m >> 1) * lazy[rt];
		lazy[rt] = 0;
	}
}

void build(int l, int r, int rt){
	lazy[rt] = 0;
	if(l == r){
		sum[rt] = A[l];
		// test
		// cout << "rt: " << rt << ", sum: " << sum[rt] << endl;
		return;
	}
	int m = (l + r) >> 1;
	build(lson);
	build(rson);
	PushUp(rt);
}

void update_add(int L, int R, int val, int l, int r, int rt){
	if(L <= l && r <= R){
		lazy[rt] += val;
		sum[rt] += (LL)val * (r - l + 1);
		return;
	}
	PushDown(rt, r - l + 1);
	int m = (l + r) >> 1;
	if(L <= m){
		update_add(L, R, val, lson);
	}
	if(m < R){
		update_add(L, R, val, rson);
	}
	PushUp(rt);
}

LL query_sum(int L, int R, int l, int r, int rt){
	if(L <= l && r <= R){
		return sum[rt];
	}
	PushDown(rt, r - l + 1);
	int m = (l + r) >> 1;
	LL ret = 0;
	if(L <= m){
		ret += query_sum(L, R, lson);
	}
	if(m < R){
		ret += query_sum(L, R, rson);
	}
	return ret;
}

int main(){
	int N, Q, a, b, c;
	char ch;
	scanf("%d %d", &N, &Q);
	for(int i = 1; i <= N ; i++){
		scanf("%d", &A[i]);
	}
	build(1, N, 1);
	while(Q--){
		getchar();
		ch = getchar();
		if(ch == 'Q'){
			scanf("%d %d", &a, &b);
			printf("%lld\n", query_sum(a, b, 1, N, 1));
		}
		else if(ch == 'C'){
			scanf("%d %d %d",&a, &b, &c);
			// test
			// cout << "a: " << a << ", b: " << b << ", c: " << c << endl;
			update_add(a, b, c, 1, N, 1);
		}
	}
	return 0;
}
