#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
using pii = pair<int, int>;
const pii dum = { -1, -1 };
bool board[20][20];
int v[20][20][20][20];
char ch;
pii c1 = dum, c2 = dum;
int N, M, ans = -1;
int dy[4] = { -1, 1, 0 ,0 };
int dx[4] = { 0, 0, -1, 1 };
bool inRange(int y, int x)
{
	return y >= 0 && x >= 0 && y < N && x < M;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	memset(v, -1, sizeof(v));
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
		{
			cin >> ch;
			if (ch == '#') board[i][j] = true;
			else
			{
				board[i][j] = false;
				if (ch == 'o')
				{
					if (c1 == dum) c1 = { i, j };
					else c2 = { i, j };
				}
			}
		}
	v[c1.first][c1.second][c2.first][c2.second] = 0;
	queue<pair<pii, pii>> q;
	q.push({ c1, c2 });
	while (!q.empty() && ans < 0)
	{
		pii n1 = q.front().first;
		pii n2 = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			pii nn1 = { n1.first + dy[i], n1.second + dx[i] };
			pii nn2 = { n2.first + dy[i], n2.second + dx[i] };
			if (!inRange(nn1.first, nn1.second) && !inRange(nn2.first, nn2.second))
				continue;
			else if (!inRange(nn1.first, nn1.second) || !inRange(nn2.first, nn2.second))
			{
				ans = v[n1.first][n1.second][n2.first][n2.second] + 1;
				break;
			}
			if (board[nn1.first][nn1.second]) nn1 = n1;
			if (board[nn2.first][nn2.second]) nn2 = n2;
			if (v[nn1.first][nn1.second][nn2.first][nn2.second] >= 0) continue;
			v[nn1.first][nn1.second][nn2.first][nn2.second] = v[n1.first][n1.second][n2.first][n2.second] + 1;
			if (v[nn1.first][nn1.second][nn2.first][nn2.second] > 10) continue;
			q.push({ nn1, nn2 });
		}
	}
	if (ans > 10) ans = -1;
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/16197