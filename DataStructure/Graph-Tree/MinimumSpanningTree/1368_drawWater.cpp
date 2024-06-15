#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N, W, C, P[302], ans = 0;

vector<pair<int, pair<int, int>>> E;

int find(int u)
{
	if (u == P[u]) return u;
	return P[u] = find(P[u]);
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
	cin >> N;
	for (int i = 1; i <= N; i++) P[i] = i;
	for (int i = 0; i < N; i++)
	{
		cin >> W;
		E.push_back({ W, {i, N} });
	}
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{
			cin >> C;
			if (i < j)
				E.push_back({ C, {i, j} });
		}
	sort(E.begin(), E.end());
	for (int i = 0; i < E.size(); i++)
	{
		int a = E[i].second.first;
		int b = E[i].second.second;
		int c = E[i].first;
		if (find(a) == find(b)) continue;
		merge(a, b);
		ans += c;
	}
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/1368