#include <iostream>
#include <queue>

using namespace std;

int N, M, K, T, MY[90001], MX[90001], KY[90001], KX[90001];
bool v[301][301][2];
int dy[8] = { -1, -1, -2, -2, 1, 1, 2, 2 };
int dx[8] = { 2, -2, 1, -1, 2, -2, 1, -1 };
queue<pair<pair<int, int>, bool>> q;
bool clean = false;
bool inRange(int y, int x)
{
	return y > 0 && x > 0 && y <= N && x <= N;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M >> K >> T;
	for (int i = 0; i < M; i++)
	{
		cin >> MY[i] >> MX[i];
		bool c = false;
		for (int d = 0; d < 8 && !c; d++)
		{
			if (inRange(MY[i] + dy[d], MX[i] + dx[d]))
				c = true;
		}
		if (c)
		{
			v[MY[i]][MX[i]][0] = true;
			q.push({ {MY[i], MX[i]} , 0 });
		}
	}
	for (int i = 0; i < K; i++) cin >> KY[i] >> KX[i];
	for (int t = 0; t < T; t++)
	{
		int s = q.size();
		while (s--)
		{
			int y = q.front().first.first;
			int x = q.front().first.second;
			bool p = q.front().second;
			q.pop();
			for (int d = 0; d < 8; d++)
			{
				int ny = y + dy[d];
				int nx = x + dx[d];
				if (inRange(ny, nx) && !v[ny][nx][!p])
				{
					v[ny][nx][!p] = true;
					q.push({ {ny, nx}, !p });
				}
			}
		}
	}
	for (int i = 0; i < K; i++)
	{
		if (v[KY[i]][KX[i]][T % 2])
		{
			clean = true;
			break;
		}
	}
	if (clean) cout << "YES\n";
	else cout << "NO\n";
}

// https://www.acmicpc.net/problem/15806