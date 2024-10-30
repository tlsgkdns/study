#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, pair<int, int>>> edges;
int N, M, K, P[1001], E[1001], U, W, V, ans = 0;

int find(int a)
{
	if (a == P[a]) return a;
	return P[a] = find(P[a]);
}
void merge(int a, int b)
{
	a = find(a); b = find(b);
	if (a < b) swap(a, b);
	P[b] = a;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M >> K;
	for (int i = 0; i <= N; i++) P[i] = i;
	for (int i = 0; i < K; i++)
	{
		cin >> E[i];
		for (int idx = 0; idx < i; idx++)
			merge(E[idx], E[i]);
	}
	for (int i = 0; i < M; i++)
	{
		cin >> U >> V >> W;
		edges.push_back({ W, {U, V} });
	}
	sort(edges.begin(), edges.end());
	for (int i = 0; i < edges.size(); i++)
	{
		int cost = edges[i].first;
		int from = edges[i].second.first;
		int to = edges[i].second.second;
		if (find(from) != find(to))
		{
			merge(from, to);
			ans += cost;
		}
	}
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/10423