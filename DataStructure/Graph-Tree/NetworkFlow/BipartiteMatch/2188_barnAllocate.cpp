#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int INF = 201;
vector<int> adj[INF];
int v[INF], c[INF];
int N, M, Si, S, ans = 0;
bool dfs(int x)
{
	if (v[x]) return false;
	v[x] = true;
	for (int e : adj[x])
		if (c[e] < 0 || dfs(c[e]))
		{
			c[e] = x;
			return true;
		}
	return false;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
	{
		cin >> S;
		for (int s = 0; s < S; s++)
		{
			cin >> Si;
			adj[i].push_back(Si);
		}
	}
	memset(c, -1, sizeof(c));
	for (int i = 1; i <= N; i++)
	{
		memset(v, false, sizeof(v));
		ans += dfs(i);
	}
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/2188