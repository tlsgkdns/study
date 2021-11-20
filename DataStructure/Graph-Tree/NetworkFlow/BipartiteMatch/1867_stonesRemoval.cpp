#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> adj;
vector<bool> v;
vector<int> c;

int N, M, a, b;

bool dfs(int here)
{
	if (v[here]) return false;
	v[here] = true;
	for (int there : adj[here])
	{
		if (c[there] == -1 || dfs(c[there]))
		{
			c[there] = here;
			return true;
		}
	}
	return false;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	adj.resize(N + 1); c.resize(N + 1, -1);
	v.resize(N + 1, false);
	for (int i = 0; i < M; i++)
	{
		cin >> a >> b;
		adj[a].push_back(b);
	}
	int ans = 0;
	for (int i = 1; i <= N; i++)
	{
		v = vector<bool>(N + 1, false);
		if (dfs(i)) ans++;
	}
	cout << ans << '\n';
}