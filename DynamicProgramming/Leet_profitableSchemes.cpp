#include <vector>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;


class Solution {
public:
	int dp[101][101][101] = { -1 };
	int schemeNum = 0, maxMember = 0;
	int mod = 1000000007;
	int solve(vector<int>& group, vector<int>& profit, int idx, int minProfit, int member)
	{
		int& ret = dp[idx][minProfit][member];
		if (ret != -1) return ret;
		if (idx == schemeNum)	return ret = (minProfit == 0);
		if (member + group[idx] > maxMember) ret = solve(group, profit, idx + 1, minProfit, member);
		else ret = solve(group, profit, idx + 1, max(0, minProfit - profit[idx]), member + group[idx]) % mod +
			solve(group, profit, idx + 1, minProfit, member) % mod;
		ret %= mod;
		return ret;
	}
	int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
		memset(dp, -1, sizeof(dp));
		schemeNum = group.size();
		maxMember = n;
		return solve(group, profit, 0, minProfit, 0);
	}
};
int main()
{
	int n, mp, sc, gr, pr;
	vector<int> g, p;
	cin >> n >> mp >> sc;
	for (int i = 0; i < sc; i++)
	{
		cin >> gr;
		g.push_back(gr);
	}
	for (int i = 0; i < sc; i++)
	{
		cin >> pr;
		p.push_back(pr);
	}
	Solution* s = new Solution();
	cout << s->profitableSchemes(n, mp, g, p) << '\n';
}

// https://leetcode.com/problems/profitable-schemes/