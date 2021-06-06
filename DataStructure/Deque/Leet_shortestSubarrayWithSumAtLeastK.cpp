Sub#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <queue>
using namespace std;

class Solution {
public:
	int shortestSubarray(vector<int>& nums, int k) {
		deque<int> dq; int sum = 0;
		int n = nums.size();
		vector<int> psum(n + 1, 0); psum[1] = nums[0];
		for (int i = 1; i < n; i++)
			psum[i + 1] = nums[i] + psum[i];
		int ans = INT_MAX;
		for (int i = 0; i < n + 1; i++)
		{
			int a = psum[i];
			while (!dq.empty() && a < psum[dq.back()])
				dq.pop_back();
			while (!dq.empty() && a - psum[dq.front()] >= k)
			{
				ans = min(ans, i - dq.front());
				dq.pop_front();
			}
			dq.push_back(i);
		}
		ans = (ans == INT_MAX) ? -1 : ans;
		return ans;
	}
};

int main()
{
	int l, k;
	cin >> l;
	vector<int> nums(l);
	for (int i = 0; i < l; i++)
		cin >> nums[i];
	cin >> k;
	Solution s;
	cout << s.shortestSubarray(nums, k) << '\n';
}

// https://leetcode.com/problems/shortest-subarray-with-sum-at-least-k/