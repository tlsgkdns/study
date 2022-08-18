#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX = 1025;
vector<int> group, adj[MAX];
vector<pair<int, pair<int, int>>> edge;
int N, C;
int find(int a)
{
	if (a == group[a]) return a;
	return group[a] = find(group[a]);
}
void merge(int p, int q)
{
	if (p > q) swap(p, q);
	int a = find(p), b = find(q);
	group[a] = b;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = i + 1; j < N; j++)
		{
			cin >> C;
			edge.push_back({ C, {i, j} });
		}
	}
	sort(edge.begin(), edge.end());
	group.resize(N);
	for (int i = 0; i < N; i++) group[i] = i;
	for (auto e : edge)
	{
		if (find(e.second.first) != find(e.second.second))
		{
			adj[e.second.first].push_back(e.second.second);
			adj[e.second.second].push_back(e.second.first);
			merge(e.second.first, e.second.second);
		}
	}
	for (int i = 0; i < N; i++) sort(adj[i].begin(), adj[i].end());
	for (int i = 0; i < N; i++)
	{
		cout << adj[i].size() << " ";
		for (int j = 0; j < adj[i].size(); j++)
			cout << adj[i][j] + 1 << " ";
		cout << '\n';
	}
}

// https://www.acmicpc.net/problem/6091