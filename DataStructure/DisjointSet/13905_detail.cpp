#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int P[100001], N, M, S, E, H1, H2, K, ans = 0;
vector<pair<int, pair<int, int>>> edges;

int find(int u)
{
	if (P[u] == u) return u;

	return P[u] = find(P[u]);
}
void merge(int u, int v)
{
	u = find(u); v = find(v);
	if (u < v) swap(u, v);
	P[u] = v;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	for (int i = 1; i <= N; i++) P[i] = i;
	cin >> S >> E;
	for (int i = 0; i < M; i++)
	{
		cin >> H1 >> H2 >> K;
		edges.push_back({ -K, {H1, H2} });
	}
	sort(edges.begin(), edges.end());
	for (int i = 0; i < edges.size(); i++)
	{
		int cost = -edges[i].first;
		int a = edges[i].second.first;
		int b = edges[i].second.second;
		merge(a, b);
		if (find(S) == find(E))
		{
			ans = cost;
			break;
		}
	}
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/13905