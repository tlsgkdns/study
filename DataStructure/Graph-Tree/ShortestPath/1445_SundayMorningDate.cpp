#include <iostream>
#include <queue>
using namespace std;
using pii = pair<int, int>;
priority_queue<pair<pii, pii>> pq;
pii S, D, dist[51][51];
const int INF = 1000000007;
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0 ,0, -1, 1 };
int N, M, G[51][51];
char C;
bool inRange(int y, int x)
{
	return y >= 0 && x >= 0 && y < N && x < M;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
		{
			dist[i][j] = { INF, INF };
			cin >> C;
			if (C == 'F')
			{
				D = { i, j };
				G[i][j] = -1;
			}
			if (C == 'S')
			{
				S = { i, j };
				G[i][j] = -1;
			}

			if (C == 'g') G[i][j] = 1;
		}
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
		{
			if (G[i][j] != 1) continue;
			for (int d = 0; d < 4; d++)
			{
				int ny = i + dy[d];
				int nx = j + dx[d];
				if (!inRange(ny, nx) || G[ny][nx] != 0) continue;
				G[ny][nx] = 2;
			}
		}

	pq.push({ {0, -(G[S.first][S.second] == 2)}, S });
	dist[S.first][S.second] = { 0, (G[S.first][S.second] == 2) };
	while (!pq.empty())
	{
		int g = -pq.top().first.first;
		int a = -pq.top().first.second;
		int y = pq.top().second.first;
		int x = pq.top().second.second;
		pq.pop();
		if (make_pair(y, x) == D)
		{
			cout << g << " " << a << '\n';
			break;
		}
		for (int d = 0; d < 4; d++)
		{
			int ny = y + dy[d];
			int nx = x + dx[d];
			if (!inRange(ny, nx)) continue;
			int na = a + (G[ny][nx] == 2);
			int ng = g + (G[ny][nx] == 1);
			if (dist[ny][nx].first > ng || (dist[ny][nx].first == ng && dist[ny][nx].second > na))
			{
				dist[ny][nx] = { ng, na };
				pq.push({ {-ng, -na}, {ny, nx} });
			}
		}
	}
}

// https://www.acmicpc.net/problem/1445