#include<iostream>
#include<cstdio>
#include<cstring>
#include<climits>
#include<algorithm>
using namespace std;

#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1
const int MAX_N = 100005;

int A[MAX_N];
int MAX[MAX_N << 2];
int MIN[MAX_N << 2];
int SUM[MAX_N << 2];

// update from down to top
void PushUp(int rt){
	MAX[rt] = max(MAX[rt << 1], MAX[rt << 1 | 1]);
	MIN[rt] = min(MIN[rt << 1], MIN[rt << 1 | 1]);
	SUM[rt] = SUM[rt << 1] + SUM[rt << 1 | 1];
}

void build(int l, int r, int rt){
	if(l == r){
		MAX[rt] = MIN[rt] = SUM[rt] = A[l];
		// test
		cout << "rt: " << rt << ", min: " << MIN[rt] << ", max: " << MAX[rt] << ", sum: " << SUM[rt] << endl;
		return;
	}
	int m = (l + r) >> 1;
	build(lson);
	build(rson);
	PushUp(rt);
}

// do the substitution for the position a with b
void update_rep(int pos, int val, int l, int r, int rt){
	if(l == r){
		MAX[rt] = MIN[rt] = SUM[rt] = val;
		return;
	}
	int m = (l + r) >> 1;
	if(pos <= m){
		update_rep(pos, val, lson);
	}
	else{
		update_rep(pos, val, rson);
	}
	PushUp(rt);
}

// do the addition/substraction to/from the value
void update_add(int pos, int val, int l, int r, int rt){
	if(l == r){
		SUM[rt] += val;
		return;
	}
	int m = (l + r) >> 1;
	if(pos <= m){
		update_add(pos, val, lson);
	}
	else{
		update_add(pos, val, rson);
	}
	PushUp(rt);
}

// get the max value in the interval: [L, R]
int query_max(int L, int R, int l, int r, int rt){
	if(L <= l && r <= R){
		return MAX[rt];
	}
	int m = (l + r) >> 1;
	int ret = -1;
	if(L <= m){
		ret = max(ret, query_max(L, R, lson));
	}
	if(R > m){
		ret = max(ret, query_max(L, R, rson));
	}
	return ret;
}

// get the min value in the interval: [L, R]
int query_min(int L, int R, int l, int r, int rt){
	if(L <= l && r <= R){
		return MIN[rt];
	}
	int m = (l + r) >> 1;
	int ret = INT_MAX;
	if(L <= m){
		ret = min(ret, query_min(L, R, lson));
	}
	if(R > m){
		ret = min(ret, query_min(L, R, rson));
	}
	return ret;
}

// get the sum in the interval: [L, R]
int query_sum(int L, int R, int l, int r, int rt){
	if(L <= l && r <= R){
		return SUM[rt];
	}
	int m = (l + r) >> 1;
	int ret = 0;
	if(L <= m){
		ret += query_sum(L, R, lson);
	}
	if(R > m){
		ret += query_sum(L, R, rson);
	}
	return ret;
}

int main(){
	int n, m;
	while(~scanf("%d %d",&n, &m)){
		for(int i = 1; i <= n; i ++){
			scanf("%d", &A[i]);
		}		
		build(1, n, 1);
		// test
		cout << "build ends!" << endl;
		while(m--){
			char op[10];
			int a, b;
			scanf("%s %d %d", op, &a, &b);
			// get the max value in the interval: [a, b]
			if(strcmp(op, "max") == 0){
				cout << "max: " << query_max(a, b, 1, n, 1) << endl;
			}
			// get the min value in the interval: [a, b]
			else if(strcmp(op, "min") == 0){
				cout << "min: " << query_min(a, b, 1, n, 1) << endl;
			}
			// get the sum in the interval: [a, b]
			else if(strcmp(op, "sum") == 0){
				cout << "sum: " << query_sum(a, b, 1, n, 1) << endl;
			}
			// do the substitution for the position a with b
			else if(strcmp(op, "rep") == 0){
				update_rep(a, b, 1, n, 1);
			}
			// do the addition to the value
			else if(strcmp(op, "add") == 0){
				update_add(a, b, 1, n, 1);
			}
			// do the substraction from the value
			else if(strcmp(op, "sub") == 0){
				update_add(a, -b, 1, n, 1);
			}
		}
	}
	return 0;
}
