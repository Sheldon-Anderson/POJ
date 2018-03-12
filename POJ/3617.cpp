#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<string>
#include<set>
#include<map>
#include<algorithm>
#include<queue>

using namespace std;

int N;
char in[2005], out[2005];

int main() {
	cin >> N;
	for (int i = 0; i <= N - 1; i++) {
		cin >> in[i];
	}
	int i = 0, j = N - 1, s, e, cnt = 0;
	while (i < j) {
		if (in[i] < in[j]) {
			out[cnt++] = in[i++];
		}
		else if (in[i] > in[j]) {
			out[cnt++] = in[j--];
		}
		else {
			s = i;
			e = j;
			while (s < e) {
				if (in[s] == in[e]) {
					s++;
					e--;
				}
				else if (in[s] < in[e]) {
					out[cnt++] = in[i++];
					break;
				}
				else if (in[s] > in[e]) {
					out[cnt++] = in[j--];
					break;
				}
			}
			if (s >= e) {
				// or out[cnt++] = in[j--]
				out[cnt++] = in[i++];
			}
		}
	}
	if (i == j) {
		out[cnt++] = in[i];
	}
	for (int i = 0; i <= N - 1; i++) {
		cout << out[i];
		if (i % 80 == 79) {
			cout << endl;
		}
	}
	if ((N - 1) % 80 != 79) {
		cout << endl;
	}
	return 0;
}
