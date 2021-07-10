#include <iostream>
#include <bitset>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

class Solution {
public:
	int dp[1 << 15];
	int gcd(int a, int b)
	{
		int n;
		if (a < b) return gcd(b, a);
		while (b != 0)
		{
			n = a % b;
			a = b;
			b = n;
		}
		return a;
	}
	int getScore(int idx, int a, int b)
	{
		return idx * gcd(a, b);
	}
	int solve(vector<int>& num, bitset<14> b, int d)
	{
		int id = b.to_ulong();
		if (id == (1 << num.size()) - 1) return dp[id] = 0;
		if (dp[id] != -1) return dp[id];
		for (int i = 0; i < num.size(); i++)
		{
			if (b.test(i)) continue;
			for (int j = i + 1; j < num.size(); j++)
			{
				if (b.test(j)) continue;
				b.set(i); b.set(j);
				dp[id] = max(dp[id], solve(num, b, d + 1) + getScore(d + 1, num[i], num[j]));
				b.reset(i); b.reset(j);
			}
		}
		return dp[id];
	}
	int maxScore(vector<int>& nums) {
		memset(dp, -1, sizeof(dp));
		bitset<14> bt; bt.reset();
		return solve(nums, bt, 0);
	}
};

int main()
{
	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	Solution* s = new Solution();
	cout << s->maxScore(arr) << '\n';
}

// https://leetcode.com/problems/maximize-score-after-n-operations/