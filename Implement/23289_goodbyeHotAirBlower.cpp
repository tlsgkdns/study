#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> room, wall, temper;

int dx[6] = { 0, 0, 0, -1, 1 };
int dy[6] = { 0, 1, -1, 0, 0 };

int R, C, K, W, X, Y, T;
void addWall(int x, int y, int t)
{
	if (t == 0)
	{
		wall[x][y] |= (1 << 3);
		wall[x - 1][y] |= (1 << 4);
	}
	else
	{
		wall[x][y] |= (1 << 1);
		wall[x][y + 1] |= (1 << 2);
	}
}
bool inRange(int x, int y)
{
	return (x > 0 && y > 0 && x <= R && y <= C);
}
bool isThereWall(int x, int y, int d)
{
	return wall[x][y] & (1 << d);
}
bool isThereWall(int x1, int y1, int x2, int y2)
{
	for (int d = 1; d <= 4; d++)
	{
		int nx = x1 + dx[d];
		int ny = y1 + dy[d];
		if (inRange(nx, ny) && isThereWall(x1, y1, d) && nx == x2 && ny == y2)
			return true;
	}
	return false;
}
void spreadWind()
{
	for (int i = 1; i <= R; i++)
		for (int j = 1; j <= C; j++)
		{
			if (room[i][j] == 0 || room[i][j] == 5) continue;
			vector<vector<int>> v(R + 1, vector<int>(C + 1, 0));
			int dir = room[i][j];
			int sx = i + dx[dir];
			int sy = j + dy[dir];
			queue<pair<int, int>> q;
			v[sx][sy] = 5;
			q.push({ sx, sy });
			while (!q.empty())
			{
				int x = q.front().first;
				int y = q.front().second;
				q.pop();
				for (int d = 3; d <= 5; d++)
				{
					int nx = (dir <= 2) ? x + dx[d] : ((dir == 3) ? x - 1 : x + 1);
					int ny = (dir <= 2) ? ((dir == 1) ? y + 1 : y - 1) : y + dx[d];
					if (!inRange(nx, ny) || v[nx][ny] > 0 || isThereWall(x, y, nx, ny)) continue;
					if (dir <= 2 && (isThereWall(nx, y, nx, ny) || isThereWall(x, y, nx, y))) continue;
					if (dir > 2 && (isThereWall(x, y, x, ny) || isThereWall(x, ny, nx, ny))) continue;
					v[nx][ny] = v[x][y] - 1;
					if (v[nx][ny] == 1) continue;
					q.push({ nx, ny });
				}
			}
			for (int r = 1; r <= R; r++)
				for (int c = 1; c <= C; c++)
					temper[r][c] += v[r][c];
		}
}

void adjustTemper()
{
	vector<vector<int>> tmp(R + 1, vector<int>(C + 1, 0));
	for (int r = 1; r <= R; r++)
		for (int c = 1; c <= C; c++)
		{
			for (int d = 1; d <= 4; d += 3)
			{
				if (isThereWall(r, c, d)) continue;
				int nr = r + dx[d];
				int nc = c + dy[d];
				if (!inRange(nr, nc)) continue;
				pair<int, int> high = { nr, nc }, low = { r, c };
				if (temper[r][c] > temper[nr][nc]) swap(high, low);
				int sub = (temper[high.first][high.second] - temper[low.first][low.second]) / 4;
				tmp[high.first][high.second] -= sub;
				tmp[low.first][low.second] += sub;
			}
		}
	for (int r = 1; r <= R; r++)
		for (int c = 1; c <= C; c++)
			temper[r][c] += tmp[r][c];
}

void reduceTemper()
{
	for (int r = 1; r <= R; r++)
	{
		if (temper[r][1] >= 1) temper[r][1]--;
		if (temper[r][C] >= 1) temper[r][C]--;
	}
	for (int c = 2; c < C; c++)
	{
		if (temper[R][c] >= 1) temper[R][c]--;
		if (temper[1][c] >= 1) temper[1][c]--;
	}
}
bool check()
{
	for (int r = 1; r <= R; r++)
		for (int c = 1; c <= C; c++)
			if (room[r][c] == 5 && temper[r][c] < K)
				return false;
	return true;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> R >> C >> K;
	room.resize(R + 1, vector<int>(C + 1));
	wall.resize(R + 1, vector<int>(C + 1));
	temper.resize(R + 1, vector<int>(C + 1, 0));
	for (int i = 1; i <= R; i++)
		for (int j = 1; j <= C; j++)
			cin >> room[i][j];
	cin >> W;
	for (int i = 0; i < W; i++)
	{
		cin >> X >> Y >> T;
		addWall(X, Y, T);
	}
	int ans = 0;
	do
	{
		spreadWind();
		adjustTemper();
		reduceTemper();
		ans++;
		if (ans > 100) break;
	} while (!check());
	cout << ans << '\n';
}
// https://www.acmicpc.net/problem/23289