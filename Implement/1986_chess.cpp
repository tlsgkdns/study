#include <iostream>
#include <vector>
using namespace std;

int N, M, q, r, c, k, p;
vector<vector<char>> piece;
vector<vector<bool>> obs;
int qdy[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int qdx[8] = { 0, -1, 1, 1, -1, 0, -1, 1 };
int kdy[8] = { 2, 2, 1, 1, -1, -1, -2, -2 };
int kdx[8] = { -1, 1, 2, -2, 2, -2, 1, -1 };
bool inRange(int y, int x)
{
	return (y >= 0 && x >= 0 && y < N && x < M);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	obs.resize(N, vector<bool>(M, false));
	piece.resize(N, vector<char>(M, ' '));
	cin >> q;
	for (int i = 0; i < q; i++)
	{
		cin >> r >> c;
		piece[r - 1][c - 1] = 'Q';
		obs[r - 1][c - 1] = true;
	}
	cin >> k;
	for (int i = 0; i < k; i++)
	{
		cin >> r >> c;
		piece[r - 1][c - 1] = 'K';
		obs[r - 1][c - 1] = true;
	}
	cin >> p;
	for (int i = 0; i < p; i++)
	{
		cin >> r >> c;
		piece[r - 1][c - 1] = 'P';
		obs[r - 1][c - 1] = true;
	}

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
		{
			switch (piece[i][j])
			{
			case 'Q':
				for (int d = 0; d < 8; d++)
				{
					int y = i, x = j;
					while (true)
					{
						y += qdy[d]; x += qdx[d];
						if (!inRange(y, x) || piece[y][x] != ' ')
							break;
						obs[y][x] = true;
					}
				}
				break;
			case 'K':
				for (int d = 0; d < 8; d++)
				{
					int ny = i + kdy[d];
					int nx = j + kdx[d];
					if (!inRange(ny, nx)) continue;
					obs[ny][nx] = true;
				}
				break;
			}
		}
	int ans = 0;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			ans += !obs[i][j];
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/1986