#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;

#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1
const int MAX_N = 100005;

int N, M, I, J, K;
int A[MAX_N], B[MAX_N];
vector<int> tree[MAX_N << 2];

void build(int l, int r, int rt){
	// debug
	// cout << "rt: " << rt << ", l: " << l << ", r: " << r << endl;	
	if(l == r){
		tree[rt].push_back(A[l]);
		return;
	}
	int m = (l + r) >> 1;
	build(lson);
	build(rson);
	tree[rt].resize(r - l + 1);
	// merge
	merge(tree[rt << 1].begin(), tree[rt << 1].end(), tree[rt << 1 | 1].begin(), tree[rt << 1 | 1].end(), tree[rt].begin());
}

int query_cnt(int i, int j, int l, int r, int rt, int val){
	if(j < l || r < i){
		return 0;
	}
	else if(i <= l && r <= j){
		return upper_bound(tree[rt].begin(), tree[rt].end(), val) - tree[rt].begin();
	}
	else{
		int m = (l + r) >> 1;
		int cnt_l = query_cnt(i, j, l, m, rt << 1, val);
		int cnt_r = query_cnt(i, j, m + 1, r, rt << 1 | 1, val);
		return cnt_l + cnt_r;
	}
}

int main(){
	while(~scanf("%d %d", &N, &M)){
		for(int i = 1; i <= N; i++){
			scanf("%d", &A[i]);
			B[i] = A[i];
		}
		build(1, N, 1);
		// sort
		sort(B + 1, B + 1 + N);
		while(M--){
			scanf("%d %d %d", &I, &J, &K);
			int left = 1, right = N, index;
			while(left <= right){
				int mid = (left + right) >> 1;
				int cnt = query_cnt(I, J, 1, N, 1, B[mid]);
				if(cnt >= K){
					index = mid;
					right = mid - 1;
				}
				else{
					left = mid + 1;
				}
			}
			printf("%d\n", B[index]);
		}
		// clear
		for(int i = 0; i <=(N << 2) - 1; i++){
			tree[i].clear();
		}
	}
	return 0;
}
