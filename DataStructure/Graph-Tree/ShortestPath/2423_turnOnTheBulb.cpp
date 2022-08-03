#include <iostream>
#include <deque>
#include <cstring>

using namespace std;

int N, M, v[501][501], ans = -1;
char line[501][501];
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
			cin >> line[i][j];
	v[0][0] = 0;
	deque<pair<int, int>> dq;
	dq.push_back({ 0, 0 });
	while (!dq.empty())
	{
		int y = dq.front().first;
		int x = dq.front().second;
		dq.pop_front();
		if (y == N && x == M)
		{
			ans = v[y][x];
			break;
		}
		if (inRange(y - 1, x - 1))
		{
			if (line[y - 1][x - 1] == '/')
			{
				if (v[y - 1][x - 1] < 0 || v[y][x] + 1 < v[y - 1][x - 1])
				{
					v[y - 1][x - 1] = v[y][x] + 1;
					dq.push_back({ y - 1, x - 1 });
				}

			}
			else
			{
				if (v[y - 1][x - 1] < 0 || v[y][x] < v[y - 1][x - 1])
				{
					v[y - 1][x - 1] = v[y][x];
					dq.push_front({ y - 1, x - 1 });

				}
			}
		}
		if (inRange(y, x - 1))
		{
			if (line[y][x - 1] == '/')
			{
				if (v[y + 1][x - 1] < 0 || v[y][x] < v[y + 1][x - 1])
				{
					v[y + 1][x - 1] = v[y][x];
					dq.push_front({ y + 1, x - 1 });
				}
			}
			else
			{
				if (v[y + 1][x - 1] < 0 || v[y][x] + 1 < v[y + 1][x - 1])
				{
					v[y + 1][x - 1] = v[y][x] + 1;
					dq.push_back({ y + 1, x - 1 });
				}
			}
		}
		if (inRange(y - 1, x))
		{
			if (line[y - 1][x] == '/')
			{
				if (v[y - 1][x + 1] < 0 || v[y][x] < v[y - 1][x + 1])
				{
					v[y - 1][x + 1] = v[y][x];
					dq.push_front({ y - 1, x + 1 });
				}
			}
			else
			{
				if (v[y - 1][x + 1] < 0 || v[y][x] + 1 < v[y - 1][x + 1])
				{
					v[y - 1][x + 1] = v[y][x] + 1;
					dq.push_back({ y - 1, x + 1 });
				}
			}
		}
		if (inRange(y, x))
		{
			if (line[y][x] == '/')
			{
				if (v[y + 1][x + 1] < 0 || v[y][x] + 1 < v[y + 1][x + 1])
				{
					v[y + 1][x + 1] = v[y][x] + 1;
					dq.push_back({ y + 1, x + 1 });
				}
			}
			else
			{
				if (v[y + 1][x + 1] < 0 || v[y][x] < v[y + 1][x + 1])
				{
					v[y + 1][x + 1] = v[y][x];
					dq.push_front({ y + 1, x + 1 });
				}
			}
		}
	}
	if (ans == -1) cout << "NO SOLUTION\n";
	else cout << ans << '\n';
}

// https://www.acmicpc.net/problem/2423