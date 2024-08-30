#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int N, M, H, W, Sr, Sc, Fr, Fc, G, A[1001][1001], v[1001][1001];
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };
bool inRange(int y, int x)
{
	return y >= 1 && x >= 1 && y <= N && x <= M;
}
bool insideWall(int y, int x)
{
	int by = y + H - 1;
	int bx = x + W - 1;
	if (!inRange(by, bx)) return true;
	return (A[by][bx] - A[by][x - 1] - A[y - 1][bx] + A[y - 1][x - 1] > 0);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	memset(v, -1, sizeof(v));
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
		{
			cin >> G;
			A[i][j] = A[i - 1][j] + A[i][j - 1] + G - A[i - 1][j - 1];
		}
	cin >> H >> W >> Sr >> Sc >> Fr >> Fc;
	queue<pair<int, int>> q;
	q.push({ Sr, Sc });
	v[Sr][Sc] = 0;
	while (!q.empty())
	{
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		for (int d = 0; d < 4; d++)
		{
			int ny = y + dy[d];
			int nx = x + dx[d];
			if (!inRange(ny, nx) || v[ny][nx] >= 0 || insideWall(ny, nx)) continue;
			v[ny][nx] = v[y][x] + 1;
			q.push({ ny, nx });
		}
	}
	cout << v[Fr][Fc] << '\n';
}

// https://www.acmicpc.net/problem/16973