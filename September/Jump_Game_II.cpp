#include <bits/stdc++.h>
using namespace std;

int jump(vector<int>& nums);

int main() {

	int n; cin >> n;
	vector<int> nums(n);
	for(int i = 0; i < n; i++) {
		cin >> nums[i];
	}
	int res = jump(nums);
	cout << res << endl;

	return 0;
}

int jump(vector<int>& nums) {
	int ans = 0;
	int len = nums.size() - 1;
	int curr = -1;
	int next = 0;
	for(int i = 0; next < len; i++) {
		if(i > curr) {
			ans++;
			curr = next;
		}
		next = max(next, nums[i] + i);
		cout << curr << " " << next << endl;
	}
	return ans;
}