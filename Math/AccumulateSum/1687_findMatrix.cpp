#include <iostream>

using namespace std;

int N, M, ans = 0;

int G[335][335];
char ch;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
		{
			cin >> ch;
			G[i][j] = G[i - 1][j] + G[i][j - 1] - G[i - 1][j - 1] + (ch - '0');
		}
	for (int i = 1; i <= M; i++)
		for (int j = i; j <= M; j++)
		{
			int cnt = 0;
			for (int r = 1; r <= N; r++)
			{
				if (G[r][j] - G[r - 1][j] - G[r][i - 1] + G[r - 1][i - 1] == 0)
				{
					cnt += j - i + 1;
					ans = max(ans, cnt);
				}
				else
				{
					cnt = 0;
				}
			}
		}
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/1687