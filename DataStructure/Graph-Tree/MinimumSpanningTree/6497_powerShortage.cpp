#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int, pair<int, int>>> edges;
int M, N, X, Y, Z, P[200001];

int find(int a)
{
	if (a == P[a]) return a;
	return P[a] = find(P[a]);
}
void merge(int u, int v)
{
	if (u > v) swap(u, v);
	u = find(u); v = find(v);
	if (u == v) return;
	P[v] = u;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	while (true)
	{
		cin >> M >> N;
		if (M == 0 && N == 0) break;
		edges.clear();
		int ans = 0;
		for (int i = 0; i < M; i++) P[i] = i;
		for (int i = 0; i < N; i++)
		{
			cin >> X >> Y >> Z;
			edges.push_back({ Z, {X, Y} });
			ans += Z;
		}
		sort(edges.begin(), edges.end());
		for (int i = 0; i < edges.size(); i++)
		{
			int a = edges[i].second.first;
			int b = edges[i].second.second;
			int c = edges[i].first;
			if (find(a) == find(b)) continue;
			ans -= c;
			merge(a, b);
		}
		cout << ans << '\n';
	}
}

// https://www.acmicpc.net/problem/6497