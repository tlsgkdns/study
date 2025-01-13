#include <iostream>

using namespace std;

int N, M;
char ch;
bool c[2002][2002];
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
		{
			cin >> ch;
			if (ch == 'B') c[i][j] = true;
			else c[i][j] = false;
		}
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
		{
			for (int d = 0; d < 4; d++)
			{
				int ny = dy[d] + i;
				int nx = dx[d] + j;
				c[ny][nx] = !c[ny][nx];
			}
		}
	cout << 1 << '\n';
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
			if (c[i][j]) cout << 3;
			else cout << 2;
		cout << '\n';
	}
}

// https://www.acmicpc.net/problem/17302