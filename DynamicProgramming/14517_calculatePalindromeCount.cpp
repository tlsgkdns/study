#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> alp[27];
int dp[1001][1001], ans = 0, N;
string S;
int solve(int l, int r)
{
	if (l >= r) return 0;
	int& ret = dp[l][r];
	if (ret >= 0) return ret;
	ret = solve(l + 1, r);
	int idx = S[l] - 'a';
	for (int i = lower_bound(alp[idx].begin(), alp[idx].end(), l) - alp[idx].begin(); i < alp[idx].size() && alp[idx][i] < r; i++)
	{
		ret += solve(l + 1, alp[idx][i]) + 1;
		ret %= 10007;
	}
	return ret;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	memset(dp, -1, sizeof(dp));
	cin >> S; N = (int)S.size();
	for (int i = 0; i < N; i++)
		alp[S[i] - 'a'].push_back(i);
	int ans = solve(0, N) % 10007;
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/14517