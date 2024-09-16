#include <iostream>

using namespace std;
const int MAX = 100001;
int N, M, Q, U, V, P[MAX], W[MAX], cnt[MAX], K;

int find(int u)
{
	if (u == P[u]) return u;
	return P[u] = find(P[u]);
}
void merge(int u, int v)
{
	u = find(u); v = find(v);
	if (u > v) swap(u, v);
	if (u == v) return;
	P[v] = u;
	cnt[u] += cnt[v];
	W[u] += W[v];
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M >> Q;
	for (int i = 1; i <= N; i++)
	{
		cin >> W[i];
		P[i] = i;
		cnt[i] = 1;
	}
	while (M--)
	{
		cin >> U >> V;
		merge(U, V);
	}
	while (Q--)
	{
		cin >> K;
		K = find(K);
		if (cnt[K] < 2 * W[K]) cout << 1 << '\n';
		else cout << 0 << '\n';
	}
}

// https://www.acmicpc.net/problem/25187