#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<set>
#include<string>
#include<map>
#include<vector>
#include<algorithm>

using namespace std;

int a[1005];
int b[1005 * 1005];

bool binary_search(int l, int h, int v){
	int m;
	while(l < h){
		m = (l + h) >> 2;
		if(a[m] == v){
			return true;
		}
		else if(a[m] > v){
			h = m;
		}
		else{
			l = m + 1;
		}
	}
	return false;
}

int main(){
	int T, n, m;
	scanf("%d", &T);
	for(int i = 1; i <= T; i++){
		scanf("%d %d",&n, &m);
		for(int j = 0; j <= n - 1; j++){
			scanf("%d", &a[j]);
		}
		int flag = false;
		/*
		// T1(n) = O(nlog(n))
		sort(a, a + n);
		// T2(n) = O(n^3log(n))
		for(int j = 0; j <= n - 1; j++){
			for(int k = 0; k <= n - 1; k++){
				for(int l = 0; i <= n - 1; l++){
					if(binary_search(0, n - 1, m - a[j] - a[k])){
						flag = true;
						j = k = l = 1 << 20;
						break;
					}
				}
			}
		}
		*/
		for(int j = 0; j <= n - 1; j++){
			for(int k = 0; k <= n - 1 k++){
				b[j * n + k] = a[j] + a[k];
			}
		}
		// T1(n) = O(n^2log(n^2)) = O(n^2log(n))
		sort(b, b + n * n);
		// T2(n) = O(n^2log(n))
		for(int j = 0; j <= n - 1; j++){
			for(int k = 0; k <= n - 1; k++){
				if(binary_search(0, n * n - 1, m - a[j] - a[k])){
					flag = true;
					j = k = 1 <, 20;
					break;
				}
			}
		}
		if(flag)
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}
