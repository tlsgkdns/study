#include <iostream>

using namespace std;

const int MAX = 1000001;

char ch;
int P[MAX], N, A, B, C, cnt[MAX];

int find(int u)
{
	if (P[u] == u) return u;
	return P[u] = find(P[u]);
}

void merge(int u, int v)
{
	u = find(u); v = find(v);
	if (u > v) swap(v, u);
	if (u == v) return;
	P[u] = v;
	cnt[v] += cnt[u];
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	for (int i = 0; i < MAX; i++)
	{
		P[i] = i;
		cnt[i] = 1;
	}
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> ch;
		if (ch == 'Q')
		{
			cin >> C;
			cout << cnt[find(C)] << '\n';
		}
		else
		{
			cin >> A >> B;
			merge(A, B);
		}
	}
}

// https://www.acmicpc.net/problem/18116