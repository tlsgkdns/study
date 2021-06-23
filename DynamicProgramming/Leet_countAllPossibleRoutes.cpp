#include <iostream>
#include <cstring>
#include <vector>
#include <cmath>
using namespace std;

const long long mod = 1000000007;
class Solution {
public:
	long long dp[101][201];
	int end;
	long long solve(vector<int>& loc, int cur, int fuel)
	{
		if (fuel < 0) return 0;
		long long& ret = dp[cur][fuel];
		if (ret != -1) return ret;
		if (cur == end) ret = 1; else ret = 0;
		for (int i = 0; i < loc.size(); i++)
		{
			long long sub = abs(loc[i] - loc[cur]);
			if (cur == i || sub > fuel) continue;
			ret += solve(loc, i, fuel - sub) % mod;
		}
		return ret % mod;
	}
	int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
		memset(dp, -1, sizeof(dp));
		end = finish;
		return solve(locations, start, fuel);
	}
};
int main()
{
	int n, s, fi, fu;
	cin >> n;
	vector<int> loc(n);
	for (int i = 0; i < n; i++)
		cin >> loc[i];
	cin >> s >> fi >> fu;
	Solution so;
	cout << so.countRoutes(loc, s, fi, fu) << '\n';
}

// https://leetcode.com/problems/count-all-possible-routes/