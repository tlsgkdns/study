#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
vector<pair<int, int>> input1;
vector<int> input2;
int N, M, Q, X, Y, A, parent[100001], cnt[100001];
ll ans = 0;
bool v[100001];
int find(int u)
{
	if (u == parent[u]) return u;
	return parent[u] = find(parent[u]);
}
void merge(int a, int b)
{
	if (a < b) swap(a, b);
	a = find(a); b = find(b);
	parent[a] = b;
	if (a != b) cnt[b] += cnt[a];
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	input1.push_back({ 0, 0 });
	cin >> N >> M >> Q;
	for (int i = 1; i <= N; i++)
	{
		parent[i] = i;
		cnt[i] = 1;
	}
	for (int i = 0; i < M; i++)
	{
		cin >> X >> Y;
		input1.push_back({ X, Y });
	}
	for (int i = 0; i < Q; i++)
	{
		cin >> A;
		input2.push_back(A);
		v[A] = true;
	}
	for (int i = 1; i <= M; i++)
	{
		if (v[i]) continue;
		merge(input1[i].first, input1[i].second);
	}
	for (int i = Q - 1; i >= 0; i--)
	{
		int a = find(input1[input2[i]].first);
		int b = find(input1[input2[i]].second);
		if (a != b) ans += cnt[a] * cnt[b];
		merge(a, b);
	}
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/17398