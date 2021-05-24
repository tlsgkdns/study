#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
class Solution {
public:
	vector<vector<int>> dp;
	int n;
	int solve(vector<int>& arr, int prev, int idx)
	{
		if (idx == n) return 0;
		int& ret = dp[prev + 1][idx];
		if (ret != -1) return ret;
		if (arr[idx] == prev + 1)
			ret = solve(arr, prev, idx + 1);
		else
			ret = max(solve(arr, arr[idx], idx + 1) + arr[idx],
				solve(arr, prev, idx + 1));
		return ret;
	}
	int deleteAndEarn(vector<int>& nums) {
		n = nums.size();
		sort(nums.begin(), nums.end());
		dp.resize(nums.back() + 2, vector<int>(n, -1));
		return solve(nums, -1, 0);
	}
};

int main()
{
	Solution s;
	int n; cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	cout << s.deleteAndEarn(arr) << '\n';
}
// https://leetcode.com/problems/delete-and-earn/