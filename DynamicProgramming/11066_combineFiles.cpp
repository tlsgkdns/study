#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
using namespace std;
int T;

vector<int> files, ans, sum;
vector<vector<int>> dp;

int solve(int f, int s)
{

	int& ret = dp[f][s];
	if (ret != numeric_limits<int>::max()) return ret;
	if (f == s) return ret = 0;
	if (f + 1 == s) return ret = files[f] + files[s];
	for (int i = f; i < s; i++)
		ret = min(solve(f, i) + solve(i + 1, s) + (sum[s + 1] - sum[f]), ret);
	return ret;
}
int main()
{
	cin >> T;
	for (int t = 0; t < T; t++)
	{
		int K;
		cin >> K;
		files = vector<int>(K);
		sum = vector<int>(K + 1, 0);
		for (int i = 0; i < K; i++)
		{
			cin >> files[i];
			sum[i + 1] = files[i] + sum[i];
		}

		dp = vector<vector<int>>(K, vector<int>(K, numeric_limits<int>::max()));
		ans.push_back(solve(0, K - 1));
	}
	for (int a : ans) cout << a << '\n';
}

// https://www.acmicpc.net/problem/11066