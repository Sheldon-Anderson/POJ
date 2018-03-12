#include<bits/stdc++.h>
using namespace std;


void max_up_down_heapify(vector<int> &nums, int start, int end){
	int dad = start;
	int son = dad * 2 + 1;
	while(son <= end){
		if(son + 1 <= end && nums[son] < nums[son + 1]){
			son++;
		}
		if(nums[dad] > nums[son]){
			return;
		}
		else{
			swap(nums[dad], nums[son]);
			dad = son;
			son = dad * 2 + 1;
		}
	}
}

void heap_sort(vector<int> &nums, int len){
	for(int i = len / 2 - 1; i >= 0; i--){
		max_up_down_heapify(nums, i, len - 1);
	}
	for(int i = len - 1; i >= 1; i--){
		for(int i = 0; i <= len - 1; i++){
			cout << nums[i] << " ";
		}
		cout << endl;		
		swap(nums[0], nums[i]);
		max_up_down_heapify(nums, 0, i - 1);
	}
}

void max_insert(vector<int> &nums, int val){
	nums.push_back(val);
	int son = nums.size() - 1;
	int dad = (son - 1) / 2;
	while(dad >= 0 && son >= 1){
		// debug
		// cout << "dad: " << dad << ", son: " << son << endl;
		if(nums[dad] > nums[son]){
			return;
		}
		else{
			swap(nums[dad], nums[son]);
			son = dad;
			dad = (son - 1) / 2;
		}
	}
}

void max_delete(vector<int> &nums){
	int n = nums.size();
	swap(nums[0], nums[n - 1]);
	nums.pop_back();
	max_up_down_heapify(nums, 0, n - 2);
}

int main(){
	vector<int> a = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5};
	int len = a.size();
	// heap_sort(nums, len);
	vector<int> nums;
	for(int i = 0; i <= len - 1; i++){
		max_insert(nums, a[i]);
		for(int j = 0; j <= i; j++){
			cout << a[j] << " ";
		}
		cout << endl;
		cout << "max: " << nums[0] << endl;
	}
	cout << endl;
	for(int i = 0; i <= len - 1; i++){
		cout << "after deleting max: " << nums[0] << endl;
		max_delete(nums);
	}
	return 0;
}
