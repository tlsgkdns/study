#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;
int N, M, A, B, D[101], ans = 1000000007;
vector<int> route, adj[101];
bool c[101], v[101];
void solve()
{
	for (int i = 0; i < route.size(); i++) c[route[i]] = true;
	for (int i = 1; i <= N; i++) D[i] = 1000000007;
	priority_queue<pair<int, int>> pq;
	pq.push({ 0, 2 });
	D[2] = 0;
	while (!pq.empty())
	{
		int here = pq.top().second;
		int cost = -pq.top().first;
		pq.pop();
		if (here == 1) break;
		if ((int)route.size() + cost >= ans) break;
		for (int there : adj[here])
		{
			int nxtCost = cost + !(c[there]);
			if (D[there] <= nxtCost) continue;
			D[there] = nxtCost;
			pq.push({ -nxtCost, there });
		}
	}
	for (int i = 0; i < route.size(); i++) c[route[i]] = false;
	ans = min(ans, (int)route.size() + D[1]);
}
void dfs(int here)
{
	if (ans <= route.size()) return;
	if (here == 2)
	{
		solve();
		return;
	}
	for (int there : adj[here])
	{
		if (v[there]) continue;
		v[there] = true;
		route.push_back(there);
		dfs(there);
		v[there] = false;
		route.pop_back();
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		cin >> A >> B;
		adj[A].push_back(B);
	}
	route.push_back(1);
	v[1] = true;
	dfs(1);
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/2795