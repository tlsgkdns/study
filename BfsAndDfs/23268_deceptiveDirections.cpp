#include <iostream>
#include <queue>
#include <cmath>
#include <cstring>

using namespace std;

int W, H, sy = 0, sx = 0;
char M[1001][1001];
int v[1001][1001];
string D;
vector<int> input;
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };
bool inRange(int y, int x)
{
	return y >= 0 && x >= 0 && y < H && x < W;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	memset(v, -1, sizeof(v));
	cin >> W >> H;
	for (int i = 0; i < H; i++)
		for (int j = 0; j < W; j++)
		{
			cin >> M[i][j];
			if (M[i][j] == 'S')
			{
				sy = i;
				sx = j;
			}
		}
	cin >> D;
	for (int i = 0; i < D.size(); i++)
	{
		switch (D[i])
		{
		case 'N':
			input.push_back(0);
			break;
		case 'S':
			input.push_back(1);
			break;
		case 'W':
			input.push_back(2);
			break;
		default:
			input.push_back(3);
			break;
		}
	}
	queue<pair<int, int>> q;
	q.push({ sy, sx });
	v[sy][sx] = 0;
	while (!q.empty())
	{
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		for (int d = 0; d < 4; d++)
		{
			int ny = y + dy[d];
			int nx = x + dx[d];
			if (!inRange(ny, nx) || v[ny][nx] >= 0 || M[ny][nx] == '#') continue;
			v[ny][nx] = v[y][x] + 1;
			q.push({ ny, nx });
		}
	}
	q.push({ sy, sx });
	for (int i = 0; i < input.size(); i++)
	{
		int s = q.size();
		while (s--)
		{
			int y = q.front().first;
			int x = q.front().second;
			q.pop();
			for (int d = 0; d < 4; d++)
			{
				if (input[i] == d) continue;
				int ny = y + dy[d];
				int nx = x + dx[d];
				if (!inRange(ny, nx) || M[ny][nx] == '#' || v[ny][nx] < 0 || v[ny][nx] != i + 1) continue;
				v[ny][nx] = true;
				q.push({ ny, nx });
			}
		}
	}
	while (!q.empty())
	{
		int y = q.front().first;
		int x = q.front().second;
		M[y][x] = '!';
		q.pop();
	}
	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < W; j++)
			cout << M[i][j];
		cout << '\n';
	}
}

// https://www.acmicpc.net/problem/23268