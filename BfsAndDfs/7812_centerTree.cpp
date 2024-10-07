#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
vector<pair<int, ll>> adj[10001];
ll N, A, B, W, cnt[10001], ans = 1000000000000000007;

ll dfs(int here)
{
	ll& ret = cnt[here];
	ret = 0;
	for (int i = 0; i < adj[here].size(); i++)
	{
		int there = adj[here][i].first;
		if (cnt[there] >= 0) continue;
		ret += dfs(there) + 1;
	}
	return ret;
}
ll dfs2(int here, int p, ll s)
{
	ll ret = 0;
	for (int i = 0; i < adj[here].size(); i++)
	{
		int there = adj[here][i].first;
		if (there == p) continue;
		ret += dfs2(there, here, s + adj[here][i].second) + s + adj[here][i].second;
	}
	return ret;
}

void dfs3(int here, int p, ll s)
{
	ans = min(ans, s);
	for (int i = 0; i < adj[here].size(); i++)
	{
		int there = adj[here][i].first;
		ll cost = adj[here][i].second;
		if (there == p) continue;
		dfs3(there, here, s - cnt[there] * cost + (N - cnt[there]) * cost);
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	while (true)
	{
		cin >> N;
		if (N == 0) break;
		ans = 1000000000000000007;
		memset(cnt, -1, sizeof(cnt));
		for (int i = 0; i < N; i++) adj[i].clear();
		for (int i = 0; i < N - 1; i++)
		{
			cin >> A >> B >> W;
			adj[A].push_back({ B, W });
			adj[B].push_back({ A, W });
		}
		dfs(0);
		for (int i = 0; i < N; i++) ++cnt[i];
		dfs3(0, -1, dfs2(0, -1, 0));
		cout << ans << '\n';
	}
}

// https://www.acmicpc.net/problem/7812