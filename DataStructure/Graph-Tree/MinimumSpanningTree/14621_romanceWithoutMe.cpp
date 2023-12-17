#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> adj[1001];
int N, M, P[1001], U, V, D, ans = 0, cnt = 0;
vector<pair<int, pair<int, int>>> edge;
char G[1001];
int find(int a)
{
	if (P[a] == a) return a;
	return P[a] = find(P[a]);
}
void merge(int a, int b)
{
	a = find(a);
	b = find(b);
	if (a < b) swap(a, b);
	P[a] = b;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
	{
		cin >> G[i];
		P[i] = i;
	}
	for (int i = 0; i < M; i++)
	{
		cin >> U >> V >> D;
		if (G[U] != G[V])
			edge.push_back({ D, {U, V} });
	}
	sort(edge.begin(), edge.end());
	for (int i = 0; i < edge.size(); i++)
	{
		int a = edge[i].second.first;
		int b = edge[i].second.second;
		int c = edge[i].first;
		if (find(a) != find(b))
		{
			merge(a, b);
			ans += c;
			++cnt;
		}
	}
	if (cnt < N - 1) ans = -1;
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/14621