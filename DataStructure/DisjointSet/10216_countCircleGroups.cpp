#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;

int T, N, X[3001], Y[3001], R[3001], P[3001];
bool v[3001];
bool inCircle(int idx1, int idx2)
{
	return pow(abs(X[idx1] - X[idx2]), 2) + pow(abs(Y[idx1] - Y[idx2]), 2) <= pow(R[idx1] + R[idx2], 2);
}
int find(int u)
{
	if (u == P[u]) return u;
	return P[u] = find(P[u]);
}
void merge(int a, int b)
{
	a = find(a);
	b = find(b);
	if (a > b) swap(a, b);
	P[b] = a;
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
			cin >> X[i] >> Y[i] >> R[i];
			P[i] = i;
		}
		for (int i = 1; i <= N; i++)
			for (int j = i + 1; j <= N; j++)
				if (inCircle(i, j))
					merge(i, j);
		memset(v, false, sizeof(v));
		int ans = 0;
		for (int i = 1; i <= N; i++)
			if (!v[find(i)])
			{
				v[find(i)] = true;
				++ans;
			}
		cout << ans << '\n';
	}
}

// https://www.acmicpc.net/problem/10216