#include <iostream>

using namespace std;

int N, M[101][101], ans = 0;
char ch;
int dy[8] = { 1, 1, 1, 0, 0, -1, -1, -1 };
int dx[8] = { 1, -1, 0, 1, -1, 1, -1, 0 };

bool inRange(int y, int x)
{
	return y >= 0 && x >= 0 && y < N && x < N;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{
			cin >> ch;
			if (ch == '#') M[i][j] = -1;
			else M[i][j] = (ch - '0');
		}
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{
			if (M[i][j] >= 0) continue;
			bool f = true;
			for (int d = 0; d < 8; d++)
			{
				int y = i + dy[d];
				int x = j + dx[d];
				if (!inRange(y, x)) continue;
				if (M[y][x] == 0)
				{
					f = false;
					break;
				}
			}
			if (f)
			{
				++ans;
				for (int d = 0; d < 8; d++)
				{
					int y = i + dy[d];
					int x = j + dx[d];
					if (!inRange(y, x) || M[y][x] < 0) continue;
					--M[y][x];
				}
			}
		}
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/2140