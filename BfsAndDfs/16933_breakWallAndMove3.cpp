#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, -1, 0, 1 };

vector<vector<bool>> arr;
int N, M, K;
char c;

bool inRange(int y, int x)
{
	return (y >= 0 && x >= 0 && y < N && x < M);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M >> K;
	arr.resize(N, vector<bool>(M));
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
		{
			cin >> c;
			arr[i][j] = c - '0';
		}
	queue<pair<pair<int, int>, pair<int, int>>> q;
	vector<vector<vector<bool>>> v;
	v.resize(N, vector<vector<bool>>(M, vector<bool>(K + 1, false)));
	v[0][0][K] = true;
	q.push(make_pair(make_pair(0, 0), make_pair(K, 1)));
	int ans = -1;
	while (!q.empty())
	{
		int y = q.front().first.first;
		int x = q.front().first.second;
		int w = q.front().second.first;
		int cnt = q.front().second.second;
		q.pop();
		if (y == N - 1 && x == M - 1)
		{
			ans = cnt;
			break;
		}
		for (int i = 0; i < 4; i++)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (!inRange(ny, nx)) continue;
			if (arr[ny][nx] && w > 0 && !v[ny][nx][w - 1])
			{
				if ((cnt % 2) == 1)
				{
					v[ny][nx][w - 1] = true;
					q.push(make_pair(make_pair(ny, nx), make_pair(w - 1, cnt + 1)));
				}
				else
					q.push(make_pair(make_pair(y, x), make_pair(w, cnt + 1)));
			}
			if (!arr[ny][nx] && !v[ny][nx][w])
			{
				v[ny][nx][w] = true;
				q.push(make_pair(make_pair(ny, nx), make_pair(w, cnt + 1)));
			}
		}
	}
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/16933