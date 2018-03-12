#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<string>
#include<set>
#include<map>
#include<algorithm>

using namespace std;

int n;
int a[10];

int main(){
	while(scanf("%d", &n) && n >= 1 && n <= 9){
		for(int i = 1; i <= n; i++){
			a[i] = i;
		}
		do{
			for(int i = 1; i <= n; i++){
				printf("%d ", a[i]);
			}
			printf("\n");
		}while(next_permutation(a + 1, a + 1 + n));
	}
	return 0;
}
