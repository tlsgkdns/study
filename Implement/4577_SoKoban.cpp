#include <iostream>
#include <cctype>
using namespace std;

string cmd;
char G[16][16];
bool O[16][16];
int R, C, Y, X, cnt = 0;

bool inRange(int y, int x)
{
	return y >= 0 && x >= 0 && y < R && x < C;
}
void movePlayer(pair<int, int> dir)
{
	int ny = Y + dir.first;
	int nx = X + dir.second;
	if (!inRange(ny, nx) || G[ny][nx] == '#') return;
	if (G[ny][nx] == 'b')
	{
		int nny = ny + dir.first;
		int nnx = nx + dir.second;
		if (!inRange(nny, nnx) || G[nny][nnx] == '#' || G[nny][nnx] == 'b') return;
		G[ny][nx] = '.';
		G[nny][nnx] = 'b';
		Y = ny;
		X = nx;
	}
	else
	{
		Y = ny;
		X = nx;
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	while (true)
	{
		cin >> R >> C;
		if (R == 0 && C == 0) break;
		int obj = 0; ++cnt;
		for (int i = 0; i < R; i++)
			for (int j = 0; j < C; j++)
			{
				cin >> G[i][j];
				if (G[i][j] == 'W' || G[i][j] == '+' || G[i][j] == 'B')
				{
					O[i][j] = true;
					++obj;
				}
				else
					O[i][j] = false;
				if (G[i][j] == 'W' || G[i][j] == 'w')
				{
					Y = i; X = j;
					G[i][j] = '.';
				}
				if (G[i][j] == '+') G[i][j] = '.';
				if (G[i][j] == 'B') G[i][j] = 'b';
			}
		cin >> cmd;
		bool fin = false;
		for (int i = 0; i < cmd.size(); i++)
		{
			switch (cmd[i])
			{
			case 'U':
				movePlayer({ -1, 0 });
				break;
			case 'D':
				movePlayer({ 1, 0 });
				break;
			case 'R':
				movePlayer({ 0, 1 });
				break;
			case 'L':
				movePlayer({ 0, -1 });
				break;
			}
			int b = 0;
			for (int i = 0; i < R; i++)
				for (int j = 0; j < C; j++)
					b += (G[i][j] == 'b' && O[i][j]);
			if (b == obj)
			{
				fin = true;
				break;
			}
		}
		cout << "Game " << cnt << ": ";
		if (!fin) cout << "in"; cout << "complete\n";
		G[Y][X] = 'w';
		for (int i = 0; i < R; i++)
		{
			for (int j = 0; j < C; j++)
			{
				if (O[i][j])
				{
					if (G[i][j] == 'w') cout << "W";
					else if (G[i][j] == 'b') cout << "B";
					else cout << "+";
				}
				else
					cout << G[i][j];
			}
			cout << '\n';
		}
	}
}

// https://www.acmicpc.net/problem/4577