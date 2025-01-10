#include <iostream>
#include <queue>
#include <algorithm>
#include <tuple>
#include <cstring>

using namespace std;

int N, A, B, C, M, D[51][51][17], X, Y, F[51][51], SX, SY;
int dx[8] = { -2, -2, -1, -1, 1, 1, 2, 2 };
int dy[8] = { -1, 1, -2, 2, -2, 2, -1, 1 };
int dx2[4] = { -1, 1, 0, 0 };
int dy2[4] = { 0, 0, -1, 1 };

struct cmp
{
	bool operator() (const tuple<int, int, int, int>& a, const tuple<int, int, int, int>& b) {
		return get<0>(a) < get<0>(b);
	}
};
bool inRange(int x, int y)
{
	return y >= 0 && x >= 0 && y < N && x < N;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	cin >> A >> B >> C;
	cin >> SX >> SY;
	cin >> M;
	memset(F, -1, sizeof(F));
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			for (int k = 0; k <= 16; k++)
				D[i][j][k] = 1000000007;
	for (int i = 0; i < M; i++)
	{
		cin >> X >> Y;
		F[X][Y] = i;
	}
	priority_queue<tuple<int, int, int, int>, vector<tuple<int, int, int, int>>, cmp> q;
	int f = ((F[SX][SY] >= 0) ? (1 << F[SX][SY]) : 0);
	q.push(make_tuple(0, SX, SY, f));
	D[SX][SY][f] = 0;
	while (!q.empty())
	{
		int c = -get<0>(q.top());
		int x = get<1>(q.top());
		int y = get<2>(q.top());
		int f = get<3>(q.top());
		q.pop();
		if (f == (1 << M) - 1)
		{
			cout << c << '\n';
			break;
		}
		if (D[x][y][f] < c) continue;
		for (int i = 0; i < 8; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (!inRange(nx, ny)) continue;
			int nf = f | ((F[nx][ny] >= 0) ? (1 << F[nx][ny]) : 0);
			int nc = A + c;
			if (D[nx][ny][nf] > nc)
			{
				D[nx][ny][nf] = nc;
				q.push(make_tuple(-nc, nx, ny, nf));
			}
		}
		for (int d1 = -1; d1 <= 1; d1 += 2)
			for (int d2 = -1; d2 <= 1; d2 += 2)
				for (int i = 1; i < N; i++)
				{
					int nx = x + i * d1;
					int ny = y + i * d2;
					if (!inRange(nx, ny)) break;
					int nf = f | ((F[nx][ny] >= 0) ? (1 << F[nx][ny]) : 0);
					int nc = B + c;
					if (D[nx][ny][nf] > nc)
					{
						D[nx][ny][nf] = nc;
						q.push(make_tuple(-nc, nx, ny, nf));
					}
				}
		for (int d = 0; d < 4; d++)
			for (int i = 1; i < N; i++)
			{
				int nx = x + dx2[d] * i;
				int ny = y + dy2[d] * i;
				if (!inRange(nx, ny)) break;
				int nf = f | ((F[nx][ny] >= 0) ? (1 << F[nx][ny]) : 0);
				int nc = C + c;
				if (D[nx][ny][nf] > nc)
				{
					D[nx][ny][nf] = nc;
					q.push(make_tuple(-nc, nx, ny, nf));
				}
			}
	}
}

// https://www.acmicpc.net/problem/20549