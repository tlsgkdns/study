#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int X1, Y1, X2, Y2, N, M, ans = 0;
bool room[301][301], v[301][301];
char ch;
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };
vector<pair<int, int>> prv;
bool inRange(int y, int x)
{
	return y >= 0 && x >= 0 && y < N&& x < M;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	cin >> Y1 >> X1 >> Y2 >> X2;
	--Y1; --X1; --Y2; --X2;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
		{
			cin >> ch;
			if (ch == '0') room[i][j] = 0;
			else room[i][j] = 1;
		}
	prv.push_back({ Y1, X1 });
	v[Y1][X1] = true;
	while (true)
	{
		queue<pair<int, int>> q;
		while (!prv.empty())
		{
			q.push(prv.back());
			prv.pop_back();
		}
		bool br = false;
		while (!q.empty())
		{
			int y = q.front().first;
			int x = q.front().second;
			q.pop();
			if (y == Y2 && x == X2)
			{
				br = true;
				break;
			}
			for (int d = 0; d < 4; d++)
			{
				int ny = y + dy[d];
				int nx = x + dx[d];
				if (!inRange(ny, nx) || v[ny][nx]) continue;
				v[ny][nx] = true;
				if (room[ny][nx])
				{
					room[ny][nx] = false;
					prv.push_back({ ny, nx });
				}
				else
					q.push({ ny, nx });
			}
		}
		if (br) break;
		ans++;
	}
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/14497