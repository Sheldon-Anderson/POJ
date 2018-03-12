#include<cstdio>
#include<iostream>
#include<cmath>
using namespace std;

#define PAI acos(-1)
const int ST_SIZE = 1 << 15;
const int MAX_N = 10005;
const int MAX_C = 10005;

// input
int N, C;
int L[MAX_N], S[MAX_C], A[MAX_C];

// segment tree
// vectors
double vx[ST_SIZE], vy[ST_SIZE];
// angles
double ang[ST_SIZE];
// previous angles
double pre[MAX_N];

// init the segment tree
void init(int k, int l, int r){
	ang[k] = vx[k] = 0.0;
	// leaf node
	if(r - l == 1){
		vy[k] = L[l];
	}
	else{
		int m = (l + r) >> 1;
		int chl = k * 2 + 1, chr = k * 2 + 2;
		init(chl, l, m);
		init(chr, m, r);
		vy[k] = vy[chl] + vy[chr];
	}
}

// change the angles
void change(int s, double a, int v, int l, int r){
	if(s <= l){
		return;
	}
	else if(s < r){
		int chl = v * 2 + 1, chr = v * 2 + 2;
		int m = (l + r) >> 1;
		change(s, a, chl, l, m);
		change(s, a, chr, m, r);
		if(s <= m){
			ang[v] += a;
		}
		double sin_val = sin(ang[v]), cos_val = cos(ang[v]);
		vx[v] = vx[chl] + (cos_val * vx[chr] - sin_val * vy[chr]);
		vy[v] = vy[chl] + (sin_val * vx[chr] + cos_val * vy[chr]);
	}
}

int main(){
	while(~scanf("%d %d", &N, &C)){
		for(int i = 0; i <= N - 1; i++){
			scanf("%d", &L[i]);
		}
		for(int i = 0; i <= C - 1; i++){
			scanf("%d %d", &S[i], &A[i]);
		}
		// init
		init(0, 0, N);
		for(int i = 1; i <= N - 1; i++){
			pre[i] = PAI;
		}
		// solve
		for(int i = 0; i <= C - 1; i++){
			int s = S[i];
			double a =  (A[i] / 360.0) * 2 * PAI;
			change(s, a - pre[s], 0, 0, N);
			pre[s] = a;
			printf("%.2f %.2f\n", vx[0], vy[0]);
		}
		// debug
		// cout << "PAI: " << PAI << endl;
	}
	return 0;
}
