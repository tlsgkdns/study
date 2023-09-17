#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
using pii = pair<int, int>;
vector<pii> adj[1001];
const int INF = 1000000007;
int N, M, A, B, C, dp[1001], D[1001];

int dfs(int here)
{
	if (here == 2) return 1;
	int& ret = dp[here];
	if (ret >= 0) return ret;
	ret = 0;
	for (int i = 0; i < adj[here].size(); i++)
	{
		int there = adj[here][i].first;
		if (D[here] <= D[there]) continue;
		ret += dfs(there);
	}
	return ret;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	memset(dp, -1, sizeof(dp));
	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		cin >> A >> B >> C;
		adj[A].push_back({ B, C });
		adj[B].push_back({ A, C });
	}
	for (int i = 1; i <= N; i++) D[i] = INF;
	priority_queue<pii> pq;
	pq.push({ 0, 2 });
	D[2] = 0;
	while (!pq.empty())
	{
		int here = pq.top().second;
		int cost = -pq.top().first;
		pq.pop();
		if (D[here] < cost) continue;
		for (int i = 0; i < adj[here].size(); i++)
		{
			int there = adj[here][i].first;
			int nxtCost = adj[here][i].second + cost;
			if (D[there] <= nxtCost) continue;
			D[there] = nxtCost;
			pq.push({ -nxtCost, there });
		}
	}
	cout << dfs(1) << '\n';
}

// https://www.acmicpc.net/problem/2176