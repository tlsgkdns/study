#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, int>> X, Y, Z;
vector<int> parent;
vector<pair<int, pair<int, int>>> planet;
int find(int x)
{
	if (x == parent[x]) return x;

	return parent[x] = find(parent[x]);
}
void merge(int u, int v)
{
	u = find(u); v = find(v);
	if (u > v) swap(u, v);
	parent[u] = v;
}
int N, x, y, z;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	parent.resize(N, false);
	for (int i = 0; i < N; i++)
		parent[i] = i;
	for (int i = 0; i < N; i++)
	{
		cin >> x >> y >> z;
		X.push_back({ x, i });
		Y.push_back({ y, i });
		Z.push_back({ z, i });
	}
	sort(X.begin(), X.end()); sort(Y.begin(), Y.end());
	sort(Z.begin(), Z.end());
	for (int i = 0; i < N - 1; i++)
	{
		planet.push_back({ X[i + 1].first - X[i].first, {X[i].second, X[i + 1].second} });
		planet.push_back({ Y[i + 1].first - Y[i].first, {Y[i].second, Y[i + 1].second} });
		planet.push_back({ Z[i + 1].first - Z[i].first, {Z[i].second, Z[i + 1].second} });
	}
	sort(planet.begin(), planet.end());
	int ans = 0;
	for (int i = 0; i < planet.size(); i++)
	{
		int cost = planet[i].first;
		int p1 = planet[i].second.first;
		int p2 = planet[i].second.second;
		if (find(p1) != find(p2))
		{
			merge(p1, p2);
			ans += cost;
		}
	}
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/2887