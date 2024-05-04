#include <iostream>
#include <cstring>
using namespace std;

int N, M, A[1001][1001], P[1000001], cnt = 1, ans = 0;
bool v[1000001];
char G[1001][1001];

int find(int a)
{
	if (a == P[a]) return a;
	return P[a] = find(P[a]);
}
void merge(int a, int b)
{
	a = find(a);
	b = find(b);
	if (a > b) swap(a, b);
	P[b] = a;
}
void dfs(int y, int x, int n)
{
	int ny = y;
	int nx = x;
	if (G[y][x] == 'W') --nx;
	if (G[y][x] == 'S') ++ny;
	if (G[y][x] == 'N') --ny;
	if (G[y][x] == 'E') ++nx;
	if (A[ny][nx] == -1)
	{
		A[ny][nx] = n;
		dfs(ny, nx, n);
	}
	else
		merge(n, A[ny][nx]);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	memset(A, -1, sizeof(A));
	for (int i = 1; i <= N * M; i++) P[i] = i;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> G[i][j];

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			if (A[i][j] < 0)
			{
				A[i][j] = cnt;
				dfs(i, j, cnt++);
			}
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
		{
			int now = find(A[i][j]);
			if (!v[now])
			{
				v[now] = true;
				++ans;
			}
		}
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/15559