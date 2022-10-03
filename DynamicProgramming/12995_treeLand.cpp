#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
using ll = long long;
const ll MOD = 1000000007;
vector<int> adj[51];
int N, K, A, B;
ll dp[51][51][51][51], ans = 0;
bool v[51];
ll solve(int here, int prev, int l, int idx)
{
	if (l == 0) return 1;
	if (idx == adj[here].size()) return 0;
	ll& ret = dp[here][prev][l][idx];
	if (ret >= 0) return ret;
	ret = solve(here, prev, l, idx + 1);
	if (prev == adj[here][idx]) return ret;
	for (int s = 1; s <= l; s++)
		ret += (solve(adj[here][idx], here, s - 1, 0) * solve(here, prev, l - s, idx + 1)) % MOD;
	return ret;
}
void dfs(int here, int prev)
{
	ans += solve(here, prev, K - 1, 0) % MOD;
	for (int i = 0; i < adj[here].size(); i++)
	{
		int there = adj[here][i];
		if (v[there]) continue;
		v[there] = true;
		dfs(there, here);
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	memset(dp, -1, sizeof(dp));
	cin >> N >> K;
	for (int i = 0; i < N - 1; i++)
	{
		cin >> A >> B;
		adj[A].push_back(B);
		adj[B].push_back(A);
	}
	v[1] = true;
	dfs(1, 0);
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/12995