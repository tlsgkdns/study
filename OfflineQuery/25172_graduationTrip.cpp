#include <iostream>
#include <vector>
using namespace std;
const int MAX = 200001;
vector<int> adj[MAX];
int N, M, P[MAX], cnt[MAX], A, B, D[MAX];
bool v[MAX], ans[MAX];
int find(int a)
{
	if (a == P[a]) return a;
	return P[a] = find(P[a]);
}
void merge(int a, int b)
{
	a = find(a);
	b = find(b);
	if (a == b) return;
	if (a < b) swap(a, b);
	P[b] = a;
	cnt[a] += cnt[b];
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
	{
		P[i] = i;
		cnt[i] = 1;
	}
	for (int i = 0; i < M; i++)
	{
		cin >> A >> B;
		adj[A].push_back(B);
		adj[B].push_back(A);
	}
	for (int i = 0; i < N; i++) cin >> D[i];
	ans[N] = false;
	for (int i = N - 1; i >= 0; i--)
	{
		v[D[i]] = true;
		for (int idx = 0; idx < adj[D[i]].size(); idx++)
		{
			int node = adj[D[i]][idx];
			if (!v[node]) continue;
			merge(D[i], node);
		}
		if (cnt[find(D[i])] == N - i)
			ans[i] = true;
		else
			ans[i] = false;
	}
	for (int i = 0; i <= N; i++) if (ans[i]) cout << "CONNECT\n";
	else cout << "DISCONNECT\n";
}

// https://www.acmicpc.net/problem/25172