#include <iostream>
using namespace std;

int T, N, M, P[1001], C[1001], A, B;

int find(int u)
{
	if (u == P[u]) return u;
	return P[u] = find(P[u]);
}
void merge(int p, int q)
{
	p = find(p); q = find(q);
	if (p == q) return;
	if (C[p] < C[q]) swap(p, q);
	P[p] = q;
	C[q] += C[p];
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> T;
	while (T--)
	{
		cin >> N;
		for (int i = 1; i <= N; i++)
		{
			P[i] = i;
			C[i] = 1;
		}
		cin >> M;
		for (int i = 0; i < M; i++)
		{
			cin >> A >> B;
			merge(A, B);
		}
		if (N - 1 == M && C[find(1)] == N) cout << "tree\n";
		else cout << "graph\n";
	}
}

// https://www.acmicpc.net/problem/13244