#include <iostream>
#include <algorithm>
#include <cctype>
#include <vector>
using namespace std;

vector<pair<int, pair<int, int>>> E;
int N, ans = 0, cnt = 0; char ch;
int P[51];
int find(int u)
{
	if (P[u] == u) return u;
	return P[u] = find(P[u]);
}
void merge(int u, int v)
{
	if (u < v) swap(u, v);
	u = find(u); v = find(v);
	P[u] = v;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++) P[i] = i;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{
			cin >> ch;
			if (ch == '0') continue;
			int L = 0;
			if (isupper(ch)) L = (ch - 'A') + 27;
			else L = (ch - 'a') + 1;
			ans += L;
			E.push_back({ L, {i, j} });
		}
	sort(E.begin(), E.end());
	for (int i = 0; i < E.size(); i++)
	{
		int u = find(E[i].second.first), v = find(E[i].second.second);
		if (u == v) continue;
		merge(u, v);
		++cnt;
		ans -= E[i].first;
	}
	if (cnt < N - 1) ans = -1;
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/1414