#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
using pii = pair<int, int>;
vector<pii> adj[1001];
int N, K, S, Y, X, T = 0;
int L[201][201];
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };
bool inRange(int y, int x)
{
	return y > 0 && x > 0 && y <= N && x <= N;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> K;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
		{
			cin >> L[i][j];
			if (L[i][j] == 0) continue;
			adj[L[i][j]].push_back({ i, j });
		}
	cin >> S >> Y >> X;
	queue<pii> q;
	for (int i = 1; i <= K; i++)
		for (int j = 0; j < adj[i].size(); j++)
			q.push(adj[i][j]);
	while (!q.empty() && T < S)
	{
		int s = q.size();
		++T;
		for (int i = 0; i < s; i++)
		{
			int y = q.front().first;
			int x = q.front().second;
			q.pop();
			for (int d = 0; d < 4; d++)
			{
				int ny = y + dy[d];
				int nx = x + dx[d];
				if (!inRange(ny, nx) || L[ny][nx] > 0) continue;
				L[ny][nx] = L[y][x];
				q.push({ ny, nx });
			}
		}
	}
	cout << L[Y][X] << '\n';
}

// https://www.acmicpc.net/problem/18405