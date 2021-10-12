#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

const int INF = 1000000001;
int T, N, K, X, Y, W;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> T;
	vector<int> ans;
	for (int t = 0; t < T; t++)
	{
		cin >> N >> K;
		vector<vector<int>> adj(N + 1);
		vector<int> times(N + 1), dp(N + 1, 0);
		vector<int> indegree(N + 1, 0);
		for (int i = 1; i <= N; i++) cin >> times[i];
		for (int i = 0; i < K; i++)
		{
			cin >> X >> Y;
			indegree[Y]++;
			adj[X].push_back(Y);
		}
		cin >> W;
		queue<int> q;
		for (int i = 1; i <= N; i++)
			if (indegree[i] == 0)
			{
				dp[i] = times[i];
				q.push(i);
			}
		for (int n = 1; n <= N; n++)
		{
			int here = q.front();
			q.pop();
			if (here == W) break;
			for (int there : adj[here])
			{
				indegree[there]--;
				dp[there] = max(dp[here] + times[there], dp[there]);
				if (indegree[there] == 0)
					q.push(there);
			}
		}
		ans.push_back(dp[W]);
	}
	for (int a : ans) cout << a << '\n';
}

// https://www.acmicpc.net/problem/1005