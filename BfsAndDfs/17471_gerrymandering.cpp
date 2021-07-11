#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <bitset>
using namespace std;

vector<int> population;
vector<vector<bool>> adj;
bool dp[1 << 11];

const int INF = 1000000000;

int N, p, ans = INF, s = 0;

int dfs(bitset<11>& area, vector<bool>& v, int here, int f)
{
	int ret = 0;
	for (int there = 1; there <= N; there++)
		if (!v[there] && area.test(there) == f && adj[here][there])
		{
			v[there] = true;
			ret += dfs(area, v, there, f) + 1;
		}
	return ret;
}
bool canDiv(bitset<11>& area)
{
	vector<bool> v1(N + 1, false), v2(N + 1, false);
	int s1 = -1, s2 = -1;
	for (int i = 1; i <= N; i++)
	{
		if (area[i]) s1 = i;
		else s2 = i;
	}
	if (s1 == -1 || s2 == -1) return false;
	v1[s1] = true; v2[s2] = true;
	int d1 = dfs(area, v1, s1, true) + 1;
	int d2 = dfs(area, v2, s2, false) + 1;
	if (d1 + d2 == N)
		return true;
	else
		return false;
}
void solve(bitset<11>& area, int d, int popu)
{
	if (dp[area.to_ulong()] || d == N) return;
	dp[area.to_ulong()] = true;
	if (canDiv(area)) ans = min(abs(s - 2 * popu), ans);

	for (int i = 1; i <= N; i++)
	{
		if (area[i]) continue;
		area[i] = true;
		int np = popu + population[i];
		solve(area, d + 1, np);
		area[i] = false;
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N; population.resize(N + 1);
	adj.resize(N + 1, vector<bool>(N + 1, false));
	memset(dp, false, sizeof(dp));
	for (int i = 1; i <= N; i++)
	{
		cin >> population[i];
		s += population[i];
	}
	for (int i = 1; i <= N; i++)
	{
		int ad;
		cin >> p;
		for (int j = 0; j < p; j++)
		{
			cin >> ad;
			adj[i][ad] = true;
		}
	}
	bitset<11> area; area.reset();
	solve(area, 0, 0);
	if (ans == INF) ans = -1;
	cout << ans << '\n';
}
// https://www.acmicpc.net/problem/17471