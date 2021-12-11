#include <iostream>
#include <vector>
using namespace std;

vector<vector<pair<int, pair<int, int>>>> adj;
int dp[10001][101][2];
int N, M, A, B, C, D;

void dfs(int& time, int& here, int& person)
{
	if (here == N) return;
	for (int i = 0; i < adj[here].size(); i++)
	{
		int there = adj[here][i].first;
		int nextTime = time + ((person == 0) ? adj[here][i].second.first : adj[here][i].second.second);
		if (dp[nextTime][there][person]) continue;
		dp[nextTime][there][person] = true;
		dfs(nextTime, there, person);
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	adj.resize(N + 1);
	for (int i = 0; i < M; i++)
	{
		cin >> A >> B >> C >> D;
		adj[A].push_back(make_pair(B, make_pair(C, D)));
	}
	int b = 0, e = 1, t1 = 0, t2 = 0, s1 = 1, s2 = 1;
	dp[t1][s1][b] = true; dp[t2][s1][e] = true;
	dfs(t1, s1, b); dfs(t2, s2, e);
	int ans = -1;
	for (int t = 0; t <= 10000; t++)
	{
		if (dp[t][N][0] && dp[t][N][1])
		{
			ans = t;
			break;
		}
	}
	if (ans == -1) cout << "IMPOSSIBLE\n";
	else cout << ans << '\n';
}

// https://www.acmicpc.net/problem/10674