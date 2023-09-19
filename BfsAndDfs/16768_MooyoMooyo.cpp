#include <iostream>
#include <cstring>
using namespace std;

bool v[101][10];
char C[101][10];
int N, K;
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };
bool inRange(int y, int x)
{
	return y >= 0 && y < N && x >= 0 && x < 10;
}
int dfs(int y, int x)
{
	int ret = 1;
	for (int d = 0; d < 4; d++)
	{
		int ny = y + dy[d];
		int nx = x + dx[d];
		if (!inRange(ny, nx) || v[ny][nx] || C[y][x] != C[ny][nx]) continue;
		v[ny][nx] = true;
		ret += dfs(ny, nx);
	}
	return ret;
}
void pop(int y, int x)
{
	char tmp = C[y][x];
	C[y][x] = '0';
	for (int d = 0; d < 4; d++)
	{
		int ny = y + dy[d];
		int nx = x + dx[d];
		if (!inRange(ny, nx) || tmp != C[ny][nx]) continue;
		pop(ny, nx);
	}
}
void gravity()
{
	for (int x = 0; x < 10; x++)
	{
		int t = N - 1;
		while (t >= 0 && C[t][x] != '0') --t;
		if (t < 0) continue;
		for (int y = t - 1; y >= 0; y--)
			if (C[y][x] != '0')
			{
				C[t][x] = C[y][x];
				C[y][x] = '0';
				--t;
			}
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> K;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < 10; j++)
			cin >> C[i][j];
	while (true)
	{
		memset(v, false, sizeof(v));
		bool f = false;
		for (int i = 0; i < N; i++)
			for (int j = 0; j < 10; j++)
			{
				if (v[i][j] || C[i][j] == '0') continue;
				v[i][j] = true;
				if (dfs(i, j) >= K)
				{
					f = true;
					pop(i, j);
				}
			}
		if (!f) break;
		gravity();
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < 10; j++)
			cout << C[i][j];
		cout << '\n';
	}
}

// https://www.acmicpc.net/problem/16768