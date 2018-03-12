#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<string>
#include<set>
#include<map>
#include<vector>

using namespace std;

int n, k;
int a[25];

bool dfs(int i, int sum){
	if(i == n){
		return sum == k;
	}
	if(dfs(i + 1, sum)){
		return true;
	}
	if(dfs(i + 1, sum + a[i])){
		return true;
	}
	return false;
}

int main(){
	scanf("%d %sd", &n, &k);
	for(int i = 0; i <= n - 1; i++){
		scanf("%d", &a[i]);
	}
	if(dfs(0, 0)){
		printf("Yes\n");
	}
	else{
		printf("No\n");
	}
	return 0;
}
