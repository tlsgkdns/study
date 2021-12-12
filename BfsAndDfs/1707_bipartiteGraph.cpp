#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int K, V, E, u, v;
vector<int> anss;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> K;
	for (int i = 0; i < K; i++)
	{
		cin >> V >> E;
		vector<vector<int>> adj(V + 1);
		for (int e = 0; e < E; e++)
		{
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		vector<int> group(V + 1, -1);
		vector<bool> v(V + 1, false);

		bool ans = true;
		for (int n = 1; n <= V; n++)
		{
			if (!ans) break;
			if (!v[n])
			{
				v[n] = true; group[n] = 0;
				queue<int> q;
				q.push(n);
				while (!q.empty())
				{
					if (!ans) break;
					int cur = q.front();
					q.pop();
					for (int i = 0; i < adj[cur].size(); i++)
					{
						int nxt = adj[cur][i];
						if (group[nxt] != -1 && group[nxt] == group[cur])
						{
							ans = false;
							break;
						}
						if (v[nxt]) continue;
						group[nxt] = (group[cur] == 0) ? 1 : 0;
						v[nxt] = true;
						q.push(nxt);
					}
				}
			}
		}
		anss.push_back(ans);
	}
	for (int a : anss)
		if (a) cout << "YES\n";
		else cout << "NO\n";
}

// https://www.acmicpc.net/problem/1707