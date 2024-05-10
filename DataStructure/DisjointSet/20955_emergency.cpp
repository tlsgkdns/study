#include <iostream>

using namespace std;

int N, M, A, B, P[100002], ans = 0;
bool v[100002];
int find(int u)
{
	if (u == P[u]) return u;
	return P[u] = find(P[u]);
}
void merge(int a, int b)
{
	a = find(a); b = find(b);
	if (a > b) swap(a, b);
	P[b] = a;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	for (int i = 1; i <= N; i++) P[i] = i;
	for (int i = 0; i < M; i++)
	{
		cin >> A >> B;
		if (find(A) == find(B)) ++ans;
		merge(A, B);
	}
	for (int i = 1; i <= N; i++)
		if (!v[find(i)])
		{
			v[find(i)] = true;
			++ans;
		}
	cout << ans - 1 << '\n';
}

// https://www.acmicpc.net/problem/20955