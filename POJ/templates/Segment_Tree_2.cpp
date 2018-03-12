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
// int MAX[MAX_N << 2];
// int MIN[MAX_N << 2];
int lazy[MAX_N << 2];
int sum[MAX_N << 2];

// update from down to top
void PushUp(int rt){
	sum[rt] = sum[rt << 1] + sum[rt << 1 | 1];
}

// update from top to down
void PushDown(int rt, int m){
	// lazy mark
	if(lazy[rt]){
		lazy[rt << 1] = lazy[rt << 1 | 1] = lazy[rt];
		sum[rt << 1] = (m - (m >> 1)) * lazy[rt];
		sum[rt << 1 | 1] = ((m >> 1)) * lazy[rt];
		lazy[rt] = 0;
	}
}

void build(int l, int r, int rt){
	lazy[rt] = 0;
	if(l == r){
		sum[rt] = A[l];
		// test
		cout << "rt: " << rt << ", sum: " << sum[rt] << ", lazy: " << lazy[rt] << endl;
		return;
	}
	int m = (l + r) >> 1;
	build(lson);
	build(rson);
	PushUp(rt);
}

void update_rep(int L, int R, int val, int l, int r, int rt){
	if(L <= l && r <= R){
		lazy[rt] = val;
		sum[rt] = val * (r - l + 1);
		return;
	}
	PushDown(rt, r - l + 1);
	int m = (l + r) >> 1;
	if(L <= m){
		update_rep(L, R, val, lson);
	}
	if(R > m){
		update_rep(L, R, val, rson);
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
	int n, m, a, b, c;
	char op[10];
	while(~scanf("%d %d", &n, &m)){
		for(int i = 1; i <= n; i++){
			scanf("%d", &A[i]);
		}
		build(1, n, 1);
		cout << "build ends" << endl;
		while(m--){
			scanf("%s", op);
			if(strcmp(op, "rep") == 0){
				scanf("%d %d %d", &a, &b, &c);
				update_rep(a, b, c, 1, n, 1);
			}
			else if(strcmp(op, "sum") == 0){
				scanf("%d %d", &a, &b);
				cout << "sum: " << query_sum(a, b, 1, n, 1) << endl;
			}
		}
	}
	return 0;
}
