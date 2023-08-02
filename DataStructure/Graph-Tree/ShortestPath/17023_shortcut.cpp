#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
using ll = long long;
const ll INF = 1000000000000000000;
const int MAX = 10001;
vector<pair<ll, int>> adj[MAX];
vector<int> adj2[MAX + 1];
ll N, M, T, dp[MAX], D[MAX], C[MAX], a, b, t, P[MAX], ans = 0;
bool v[MAX];
ll dfs(int here)
{
	ll& ret = dp[here];
	if (ret >= 0) return ret;
	ret = C[here];
	for (int i = 0; i < adj2[here].size(); i++)
	{
		int there = adj2[here][i];
		if (v[there]) continue;
		v[there] = true;
		ret += dfs(there);
	}
	return ret;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	memset(dp, -1, sizeof(dp));
	cin >> N >> M >> T;
	for (int i = 1; i <= N; i++)
	{
		cin >> C[i];
		D[i] = INF;
		P[i] = MAX;
	}
	for (int i = 0; i < M; i++)
	{
		cin >> a >> b >> t;
		adj[a].push_back({ b, t });
		adj[b].push_back({ a, t });
	}
	D[1] = 0;
	priority_queue<pair<int, int>> pq;
	pq.push({ 0, 1 });
	while (!pq.empty())
	{
		ll cost = -pq.top().first;
		int here = pq.top().second;
		pq.pop();
		if (D[here] < cost) continue;
		for (int i = 0; i < adj[here].size(); i++)
		{
			int there = adj[here][i].first;
			ll nxtCost = adj[here][i].second + cost;
			if (D[there] == nxtCost && here < P[there]) P[there] = here;
			if (D[there] > nxtCost)
			{
				D[there] = nxtCost;
				P[there] = here;
				pq.push({ -nxtCost, there });
			}
		}
	}
	for (int i = 2; i <= N; i++) adj2[P[i]].push_back(i);
	v[1] = true; dfs(1);
	for (int i = 2; i <= N; i++)
	{
		if (T >= D[i]) continue;
		ans = max(ans, dp[i] * (D[i] - T));
	}
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/17023