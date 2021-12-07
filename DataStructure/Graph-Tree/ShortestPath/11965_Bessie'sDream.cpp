#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int INF = 1000000000;

int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };

vector<vector<int>> maze;
vector<vector<vector<int>>> v;
int N, M;
bool inRange(int y, int x)
{
	return y >= 0 && x >= 0 && y < N && x < M;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	maze.resize(N, vector<int>(M));
	v.resize(N, vector<vector<int>>(M, vector<int>(2, INF)));
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> maze[i][j];
	priority_queue<pair<int, pair<bool, pair<int, int>>>> pq;
	pq.push(make_pair(0, make_pair(false, make_pair(0, 0))));
	int ans = -1;
	while (!pq.empty())
	{
		int cost = -pq.top().first;
		bool o = pq.top().second.first;
		int y = pq.top().second.second.first;
		int x = pq.top().second.second.second;
		pq.pop();
		if (v[y][x][o] < cost) continue;
		if (y == N - 1 && x == M - 1)
		{
			ans = v[y][x][o];
			break;
		}
		for (int d = 0; d < 4; d++)
		{
			int ny = y + dy[d];
			int nx = x + dx[d];
			if (!inRange(ny, nx) || maze[ny][nx] == 0) continue;
			bool no = (maze[ny][nx] == 2 || o);
			if (maze[ny][nx] == 3 && !no) continue;
			if (maze[ny][nx] == 4)
			{
				int mv = 1;
				while (inRange(ny, nx) && maze[ny][nx] == 4)
				{
					ny += dy[d];
					nx += dx[d];
					mv++;
				}
				if (!inRange(ny, nx) || (inRange(ny, nx) && (maze[ny][nx] == 3 || maze[ny][nx] == 0)))
				{
					ny -= dy[d];
					nx -= dx[d];
					mv--;
				}
				if (v[ny][nx][maze[ny][nx] == 2] <= cost + mv) continue;
				v[ny][nx][(maze[ny][nx] == 2)] = cost + mv;
				pq.push(make_pair(-(cost + mv), make_pair((maze[ny][nx] == 2), make_pair(ny, nx))));
			}
			else
			{
				if (v[ny][nx][no] <= cost + 1) continue;
				v[ny][nx][no] = cost + 1;
				pq.push(make_pair(-(cost + 1), make_pair(no, make_pair(ny, nx))));
			}
		}
	}
	cout << ans << '\n';
}
// https://www.acmicpc.net/problem/11965