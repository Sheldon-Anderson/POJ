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

int w, h, ans, sx, sy, dirty_cnt;
int dir[4][2] = {{1, 0}, {0, -1}, {-1, 0}, {0, 1}};
char m[25][25];

void DFS(int x, int y, int cnt, int step){
	if(cnt == dirty_cnt){
		ans = min(ans, step);
		return;
	}
	if(step == 1000){
		return;
	}
	for(int i = 0; i <= 3; i++){
		int tx = x + dir[i][0];
		int ty = y + dir[i][1];
		if(tx >= 0 && tx <= h - 1 && ty >= 0 && ty <= w - 1 && m[tx][ty] != 'x'){
			if(m[tx][ty] == '.'){
				DFS(tx, ty, cnt, step + 1);
			}
			else if(m[tx][ty] == '*'){
				DFS(tx, ty, cnt + 1, step + 1);
			}
		}
	}
}

int main(){
	while(cin >> w >> h && w && h){
		for(int i = 0; i <= h - 1; i++){
			cin >> m[0];
		}
		ans = 1 << 30;
		dirty_cnt = 0;
		for(int i = 0; i <= h - 1; i++){
			for(int j = 0; j <= w - 1; j++){
				if(m[i][j] == 'o'){
					sx = i;
					sy = j;
				}
				else if(m[i][j] == '*'){
					dirty_cnt++;
				}
			}
		}
		DFS(sx, sy, 0, 0);
		if(ans == 1 << 30){
			cout << -1 << endl;
		}
		else{
			cout << ans << endl;
		}
	}
	return 0;
}
