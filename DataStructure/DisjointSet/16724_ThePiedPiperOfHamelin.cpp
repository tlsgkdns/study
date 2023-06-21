#include <iostream>
#include <cstring>
using namespace std;

int S[1001][1001], v[1001][1001];
int N, M, ans = 0, cnt = 0;
char ch;
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };
int P[1000002];
bool C[1000002];
int find(int u)
{
	if (u == P[u]) return u;
	return P[u] = find(P[u]);
}
void merge(int a, int b)
{
	if (a > b) swap(a, b);
	a = find(a);
	b = find(b);
	if (a == b) return;
	P[a] = b;
}
void dfs(int y, int x, int n)
{
	int ny = y + dy[S[y][x]];
	int nx = x + dx[S[y][x]];
	if (v[ny][nx] == -1)
	{
		v[ny][nx] = n;
		return dfs(ny, nx, n);
	}
	merge(v[ny][nx], n);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	memset(v, -1, sizeof(v));
	cin >> N >> M;
	for (int i = 0; i <= N * M; i++) P[i] = i;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
		{
			cin >> ch;
			if (ch == 'U') S[i][j] = 0;
			else if (ch == 'D') S[i][j] = 1;
			else if (ch == 'L') S[i][j] = 2;
			else S[i][j] = 3;
		}
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
		{
			if (v[i][j] >= 0) continue;
			v[i][j] = cnt;
			dfs(i, j, cnt++);
		}
	for (int i = 0; i < cnt; i++)
	{
		int n = find(i);
		if (C[n]) continue;
		C[n] = true;
		++ans;
	}
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/16724