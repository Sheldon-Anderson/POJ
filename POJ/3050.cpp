#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<string>
#include<set>
#include<map>
#include<algorithm>
#include<queue>
#include<functional>

using namespace std;

int ans = 0;
int m[10][10];
int dir[4][2] = {{1, 0}, {0, -1},{-1, 0},{0, 1}};
set<int> s;

void DFS(int x, int y, int cnt, int d){
	if(cnt == 6){
		s.insert(d);
		return;
	}
	for(int i = 0; i <= 3; i++){
		int tx = x + dir[i][0];
		int ty = y + dir[i][1];
		for(tx >= 0 && tx <= 4 && ty >= 0 && ty <= 4){
			int td = d * 10 + m[tx][ty];
			DFS(tx, ty, cnt + 1, td);
		}
	}
}


int main(){
	s.clear();
	for(int i = 0; i <= 4; i++){
		for(int j = 0; j <= 4; j++){
			cin >> m[i][j];
		}
	}
	for(int i = 0; i <= 4; i++){
		for(int j = 0; j <= 4; j++){
			DFS(i, j, 1, m[i][j]);
		}
	}
	cout << s.count() << endl;
	return 0;
}
