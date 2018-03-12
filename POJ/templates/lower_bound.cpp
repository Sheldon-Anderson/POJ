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

/*
	Ascending Sort: 
	iterator lower_bound( const key_type &key ): value >= key
	iterator upper_bound( const key_type &key ): value > key
	Descending Sort: 
	iterator lower_bound( const key_type &key ): value <= key
	iterator upper_bound( const key_type &key ): value < key
*/


int main() {
	int value;
	int a[] = { 12, 15, 17, 19, 20, 22, 23, 26, 29, 35, 40, 40, 51 };
	while (cin >> value && value) {
		// output the count of the value in the array a
		cout << upper_bound(a, a + 13, value) - lower_bound(a, a + 13, value) << endl;
		// output the first pos in the array a that a[pos] >= value
		cout << lower_bound(a, a + 13, value) - a << endl;
		// output the first a[pos] in the array a that a[pos] >= value
		cout << *lower_bound(a, a + 13, value) << endl;
	}
	return 0;
}
