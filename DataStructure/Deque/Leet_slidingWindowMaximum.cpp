#include <iostream>
#include <deque>
#include <vector>
using namespace std;


class Solution {
public:
	vector<int> maxSlidingWindow(vector<int>& nums, int k) {
		deque<int> dq;
		vector<int> ans;
		int n = nums.size();
		for (int i = 0; i < n; i++)
		{
			if (!dq.empty() && dq.front() == i - k) dq.pop_front();
			while (!dq.empty() && nums[dq.back()] < nums[i]) dq.pop_back();
			dq.push_back(i);
			if (i >= k - 1) ans.push_back(nums[dq.front()]);
		}
		return ans;
	}
};

int main()
{
	int n, k;
	cin >> n >> k;
	vector<int> nums(n);
	for (int i = 0; i < n; i++)
		cin >> nums[i];
	Solution s;
	vector<int> ans = s.maxSlidingWindow(nums, k);
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << " ";
	cout << '\n';
}

// https://leetcode.com/problems/sliding-window-maximum/