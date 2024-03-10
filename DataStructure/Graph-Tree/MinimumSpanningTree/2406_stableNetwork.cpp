#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, pair<int, int>>> E;
vector<pair<int, int>> ans;
int N, M, X, Y, adj[1001][1001], P[1001], cost = 0;
int find(int a)
{
	if (a == P[a]) return a;
	return P[a] = find(P[a]);
}
void merge(int a, int b)
{
	a = find(a);
	b = find(b);
	if (a < b) swap(a, b);
	P[b] = a;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	for (int i = 1; i <= N; i++) P[i] = i;
	for (int i = 0; i < M; i++)
	{
		cin >> X >> Y;
		merge(X, Y);
	}
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
		{
			cin >> adj[i][j];
			if (i > 1 && j > 1 && i < j) E.push_back(make_pair(adj[i][j], make_pair(i, j)));
		}
	sort(E.begin(), E.end());
	for (int i = 0; i < E.size(); i++)
	{
		if (find(E[i].second.first) == find(E[i].second.second)) continue;
		merge(E[i].second.first, E[i].second.second);
		cost += E[i].first;
		ans.push_back(E[i].second);
	}
	if (ans.empty()) cout << "0 0\n";
	else
	{
		cout << cost << " " << ans.size() << '\n';
		for (int i = 0; i < ans.size(); i++)
			cout << ans[i].first << " " << ans[i].second << '\n';
	}
}

// https://www.acmicpc.net/problem/2406