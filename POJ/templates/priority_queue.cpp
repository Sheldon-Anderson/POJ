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

priority_queue<int, vector<int>, less<int>> q1;		// decrease
priority_queue<int, vector<int>, greater<int>> q2;  // increase

int main() {
	q1.push(1);
	q1.push(4);
	q1.push(3);
	q1.push(2);
	q1.push(5);
	while (!q1.empty()) {
		int t = q1.top();
		q1.pop();
		cout << t << " ";
	}
	cout << endl;

	q2.push(1);
	q2.push(4);
	q2.push(3);
	q2.push(2);
	q2.push(5);
	while (!q2.empty()) {
		int t = q2.top();
		q2.pop();
		cout << t << " ";
	}
	cout << endl;
	
	int a[] = {1, 4, 3, 2, 5};
	int len = sizeof(a) / sizeof(int);
	cout << "len: " << len << endl;
	// greater
	sort(a, a + len, less<int>());		// increase
	for(int i = 0; i <= len - 1; i++){
		cout << a[i] << " ";
	}
	cout << endl;
	// les
	sort(a, a + len, greater<int>());	// decrease
	for(int i = 0; i <= len - 1; i++){
		cout << a[i] << " ";
	}
	cout << endl;	
	return 0;
}
