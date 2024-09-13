#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

int H, W, ans[101][101];
char ch;
queue<pair<int, int>> q;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	memset(ans, -1, sizeof(ans));
	cin >> H >> W;
	for (int i = 0; i < H; i++)
		for (int j = 0; j < W; j++)
		{
			cin >> ch;
			if (ch == 'c')
			{
				q.push({ i, j });
				ans[i][j] = 0;
			}
		}
	while (!q.empty())
	{
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		if (x + 1 >= W) continue;
		if (ans[y][x + 1] == -1 || ans[y][x + 1] > ans[y][x] + 1)
		{
			ans[y][x + 1] = ans[y][x] + 1;
			q.push({ y, x + 1 });
		}
	}
	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < W; j++)
			cout << ans[i][j] << " ";
		cout << '\n';
	}
}

// https://www.acmicpc.net/problem/10709