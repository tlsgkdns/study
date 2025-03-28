#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, M, K, P[1001], X, Y, ans[101], cnt[1001];
vector<pair<int, int>> edges;

int find(int a)
{
	if (a == P[a]) return a;
	return P[a] = find(P[a]);
}
void merge(int a, int b)
{
	a = find(a);
	b = find(b);
	if (a == b) return;
	if (a < b) swap(a, b);
	P[b] = a;
	cnt[a] += cnt[b];
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M >> K;
	for (int i = 0; i < M; i++)
	{
		cin >> X >> Y;
		edges.push_back({ X, Y });
	}
	for (int e = min(K - 1, (int)edges.size() - 1); e >= 0; e--)
	{
		for (int i = 1; i <= N; i++)
		{
			P[i] = i;
			cnt[i] = 1;
		}
		int s = 0;
		for (int i = e; i < edges.size(); i++)
		{
			int u = edges[i].first;
			int v = edges[i].second;
			if (find(u) == find(v)) continue;
			merge(u, v);
			s += (i + 1);
		}
		if (cnt[find(1)] == N) ans[e] = s;
	}
	for (int i = 0; i < K; i++) cout << ans[i] << " ";
	cout << '\n';
}

// https://www.acmicpc.net/problem/16202