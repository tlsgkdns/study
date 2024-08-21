#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
int N, P[1001];
ll C, ans = 0;
vector<pair<ll, pair<int, int>>> e;
int find(int a)
{
	if (a == P[a]) return a;
	return P[a] = find(P[a]);
}
void merge(int u, int v)
{
	u = find(u); v = find(v);
	if (u < v) swap(u, v);
	P[v] = u;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin >> N;
	for (int i = 0; i < N; i++) P[i] = i;
	cin.tie(NULL); cout.tie(NULL);
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{
			cin >> C;
			if (i == j) continue;
			e.push_back({ C, {i, j} });
		}
	sort(e.begin(), e.end());
	for (int i = 0; i < e.size(); i++)
	{
		ll c = e[i].first;
		int a = e[i].second.first;
		int b = e[i].second.second;
		if (find(a) == find(b)) continue;
		merge(a, b);
		ans += c;
	}
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/16398