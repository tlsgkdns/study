#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> adj;
vector<int> d;
vector<bool> c;
int N, M;
bool dfs(int x)
{
	for (int i = 0; i < adj[x].size(); i++)
	{
		int t = adj[x][i];
		if (c[t]) continue;
		c[t] = true;
		if (d[t] == -1 || dfs(d[t]))
		{
			d[t] = x;
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
	adj.resize(2 * N);
	d.resize(M + 1, -1); c.resize(M + 1, false);
	int a, b, n, ans = 0;
	for (int i = 0; i < N; i++)
	{
		cin >> n;
		for (int j = 0; j < n; j++)
		{
			cin >> a;
			adj[i].push_back(a);
			adj[i + N].push_back(a);
		}
	}
	for (int n = 0; n < 2 * N; n++)
	{
		c = vector<bool>(M + 1, false);
		if (dfs(n))
			ans++;
	}
	cout << ans << '\n';
}
// https://www.acmicpc.net/problem/11376