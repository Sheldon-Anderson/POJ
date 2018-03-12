#include<iostream>
#include<vector>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<climits>
#include<algorithm>
using namespace std;

#define LL long long
const int MAX_N = 100005;

int a[MAX_N], sorted_a[MAX_N];
int BUCKET_SIZE, N, M, I, J, K;
vector<int> bucket[MAX_N];

// Wrong Answer
int main(){
	while(~scanf("%d %d", &N, &M)){
		// set the size of bucket
		if(N == 1){
			BUCKET_SIZE = 1;
		}
		else{
			BUCKET_SIZE = ceil(sqrt(N * log10(N * 1.0) / log10(2.0)));
		}
		// bucket = new vector<int>[(N - 1) / BUCKET_SIZE + 1];
		// allocate the numbers in array a to the buckets
		for(int i = 0; i <= N - 1; i++){
			scanf("%d", &a[i]);
			bucket[i / BUCKET_SIZE].push_back(a[i]);
			sorted_a[i] = a[i];
		}
		// sort the array and the bucket
		sort(sorted_a, sorted_a + N);
		for(int i = 0; i <= (N - 1) / BUCKET_SIZE; i++){
			sort(bucket[i].begin(), bucket[i].end());
		}
		while(M--){
			scanf("%d %d %d",&I, &J, &K);
			I--;
			J--;
			int s1 = I / BUCKET_SIZE, s2 = J / BUCKET_SIZE;
			int left = 0, right = N - 1;
			// binary search 1
			while(left <= right){
				int mid = (left + right) >> 1;
				int val = sorted_a[mid];
				int i = I, j = J, cnt = 0;
				// numbers are not in the buckets
				while(i <= j && i <= ((s1 + 1) * BUCKET_SIZE - 1)){
					if(a[i++] <= val){
						cnt++;
					}
				}
				while(i <= j && j >= s2 * BUCKET_SIZE){
					if(a[j--] <= val){
						cnt++;
					}
				}
				// numbers in the buckets
				for(int t = s1 + 1; t <= s2 - 1; t++){
					// binary search 2
					int l = 0, r = bucket[t].size() - 1;
					while(l <= r){
						int m = (l + r) >> 1;
						if(bucket[t][m] <= K){
							l = m + 1;
						}
						else{
							r = m - 1;
						}
					}
					cnt += (r + 1);
				}
				if(cnt >= K){
					right = mid - 1;
				}
				else{
					left = mid + 1;
				}
			}
			printf("%d\n", sorted_a[left]);
		}
		// clear
		for(int i = 0; i <= (N - 1) / BUCKET_SIZE; i++){
			bucket[i].clear();
		}
	}
	return 0;
}
