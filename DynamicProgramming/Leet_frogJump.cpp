#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

class Solution
{
public:
	bool dp[2001][2001] = { false, };
	int d[3] = { 1, 0, -1 };
	bool solve(vector<int>& stones, int idx, int unit)
	{
		if (idx == stones.size() - 1) return true;
		if (unit < 0) return false;
		if (dp[idx][unit]) return false;
		dp[idx][unit] = true;
		bool ret = false;
		for (int i = 0; i < 3; i++)
		{
			if (idx == 0 && i != 1) continue;
			int nxt = unit + d[i];
			auto it = lower_bound(begin(stones), end(stones), stones[idx] + nxt);
			if (it != end(stones) && *it == stones[idx] + nxt)
			{
				int nIdx = it - stones.begin();
				ret = ret || solve(stones, nIdx, nxt);
			}
		}
		return ret;
	}
	bool canCross(vector<int>& stones)
	{
		memset(dp, false, sizeof(dp));
		return solve(stones, 0, 1);
	}
};

int main()
{
	int n;
	cin >> n;
	vector<int> s(n);
	for (int i = 0; i < n; i++)
		cin >> s[i];
	Solution* so = new Solution();
	cout << so->canCross(s) << '\n';
}

// https://leetcode.com/problems/frog-jump/