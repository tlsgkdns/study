#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> dp;
int n1, n2;
int M = 1000000000;

int solve(vector<int>& arr1, vector<int>& arr2, int idx1, int idx2, int prev)
{
	if (idx1 >= n1) return 0;
	idx2 = upper_bound(arr2.begin() + idx2, arr2.end(), prev) - arr2.begin();
	if (prev >= arr1[idx1] && idx2 >= n2) return M;
	int& ret = dp[idx1][idx2];
	if (ret == -1) return ret;
	ret = M;
	if (idx2 < n2) ret = solve(arr1, arr2, idx1 + 1, idx2, arr2[idx2]) + 1;
	if (prev < arr1[idx1]) ret = min(ret, solve(arr1, arr2, idx1 + 1, idx2, arr1[idx1]));
	return ret;
}
int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2)
{
	sort(arr2.begin(), arr2.end());
	return solve(arr1, arr2, 0, 0, -1);
}
int main()
{
	cin >> n1 >> n2;
	vector<int> arr1(n1), arr2(n2);
	dp.resize(n1 + 1, vector<int>(n2 + 1, -1));
	for (int i = 0; i < n1; i++) cin >> arr1[i];
	for (int i = 0; i < n2; i++) cin >> arr2[i];
	int ans = makeArrayIncreasing(arr1, arr2);
	if (ans >= M) ans = -1;
	cout << ans << '\n';
}

// https://leetcode.com/problems/make-array-strictly-increasing/submissions/