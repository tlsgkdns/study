#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
using ll = long long;
ll N, M, A, B, C, P[100001], ans = 0, cnt = 0;
vector<pair<ll, pair<int, int>>> edges;

int find(int a)
{
	if (a == P[a]) return a;
	return P[a] = find(P[a]);
}
void merge(int a, int b)
{
	if (a < b) swap(a, b);
	a = find(a); b = find(b);
	P[b] = a;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(NULL); cin.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		cin >> A >> B >> C;
		edges.push_back({ C, {A, B} });
		ans += C;
	}
	for (int i = 1; i <= N; i++) P[i] = i;
	sort(edges.begin(), edges.end());
	for (int i = 0; i < edges.size(); i++)
	{
		ll c = edges[i].first;
		int a = edges[i].second.first;
		int b = edges[i].second.second;
		if (find(a) == find(b)) continue;
		merge(a, b);
		ans -= c;
		++cnt;
	}
	if (cnt == N - 1) cout << ans << '\n';
	else cout << -1 << '\n';
}

// https://www.acmicpc.net/problem/21924