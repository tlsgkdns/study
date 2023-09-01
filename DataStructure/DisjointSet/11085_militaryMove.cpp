#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int MAX = 1001;
vector<pair<int, int>> adj[MAX];
int P, W, C, V, S, E, L, ans = 0;
bool v[50001];
vector<pair<int, int>> widths[50001];
int parent[MAX], K = 0;
int find(int u)
{
	if (u == parent[u]) return u;
	return parent[u] = find(parent[u]);
}
void merge(int a, int b)
{
	a = find(a); b = find(b);
	if (a > b) swap(a, b);
	parent[a] = b;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> P >> W;
	for (int i = 0; i < P; i++) parent[i] = i;
	cin >> C >> V;
	for (int i = 0; i < W; i++)
	{
		cin >> S >> E >> L;
		adj[S].push_back({ E, L });
		adj[E].push_back({ S, L });
		widths[L].push_back({ S, E });
		K = max(K, L);
	}
	for (int w = K; w >= 0; w--)
	{
		if (widths[w].empty()) continue;
		for (int i = 0; i < widths[w].size(); i++)
			merge(widths[w][i].first, widths[w][i].second);
		if (find(C) == find(V))
		{
			ans = w;
			break;
		}
	}
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/11085