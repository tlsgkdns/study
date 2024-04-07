#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<pair<pair<int, int>, int>> L;
int N, Q, X1, X2, Y, n1, n2, P[100001];

int find(int u)
{
	if (u == P[u]) return u;
	return P[u] = find(P[u]);
}
void merge(int u, int v)
{
	u = find(u);
	v = find(v);
	if (u > v) swap(u, v);
	P[u] = v;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> Q;
	for (int i = 1; i <= N; i++)
	{
		cin >> X1 >> X2 >> Y;
		L.push_back({ {X1, X2}, i });
		P[i] = i;
	}
	sort(L.begin(), L.end());
	int r = L[0].first.second, now = L[0].second;
	for (int i = 1; i < N; i++)
	{
		int a = L[i].first.first;
		int b = L[i].first.second;
		int num = L[i].second;
		if (r < a)
			now = num;
		else
			merge(now, num);
		r = max(r, b);
	}
	for (int i = 0; i < Q; i++)
	{
		cin >> n1 >> n2;
		int ans = (find(n1) == find(n2));
		cout << ans << '\n';
	}
}

// https://www.acmicpc.net/problem/17619