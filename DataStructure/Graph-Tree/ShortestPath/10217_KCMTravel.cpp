#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;


const int INF = 1000000000;
int T, N, M, K;

int main()
{
	vector<int> anss;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> T;
	for (int t = 0; t < T; t++)
	{
		cin >> N >> M >> K;
		int u, v, c, d;
		vector<vector<pair<int, pair<int, int>>>> adj(N + 1);
		vector<vector<int>> dp(N + 1, vector<int>(M + 1, INF));
		for (int i = 0; i < K; i++)
		{
			cin >> u >> v >> c >> d;
			adj[u].push_back(make_pair(v, make_pair(d, c)));
			adj[v].push_back(make_pair(v, make_pair(d, c)));
		}
		priority_queue<pair<int, pair<int, int>>> pq;
		pq.push(make_pair(0, make_pair(1, 0)));
		dp[0][0] = 0;
		while (!pq.empty())
		{
			int time = -pq.top().first;
			int here = pq.top().second.first;
			int cost = pq.top().second.second;
			pq.pop();
			if (dp[here][cost] < time) continue;
			for (int i = 0; i < adj[here].size(); i++)
			{
				int there = adj[here][i].first;
				int nextTime = time + adj[here][i].second.first;
				int nextCost = cost + adj[here][i].second.second;
				if (nextCost > M) continue;
				if (dp[there][nextCost] > nextTime)
				{
					dp[there][nextCost] = nextTime;
					pq.push(make_pair(-dp[there][nextCost], make_pair(there, nextCost)));
				}
			}
		}
		int ans = INF;
		for (int i = 0; i <= M; i++) ans = min(ans, dp[N][i]);
		anss.push_back(ans);
	}
	for (int ans : anss)
		if (ans == INF) cout << "Poor KCM\n";
		else cout << ans << '\n';
}
// https://www.acmicpc.net/problem/10217