#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<vector<vector<int>>> tomato;
int dx[6] = { 1, 0, -1, 0, 0, 0 };
int dy[6] = { 0, 1, 0, -1, 0, 0 };
int dz[6] = { 0, 0, 0, 0, 1, -1 };
int m, n, h;
int ans = -1;
int s = 0;

void bfs()
{
	queue<pair<int, int>> q;
	for (int k = 0; k < h; k++)
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				if (tomato[k][i][j] == 1)
					q.push(make_pair(k * (m * n) + i * m + j, 0));
	int prev = 0;
	bool pass = false;
	while (!q.empty())
	{
		int posZ = q.front().first / (m * n);
		int posY = (q.front().first % (m * n)) / m;
		int posX = q.front().first % m;
		int days = q.front().second;
		if (prev != days) { pass = false; prev = days; }
		if (s == 0) { ans = (pass) ? days + 1 : days; break; }
		pass = true;
		q.pop();
		for (int i = 0; i < 6; i++)
		{
			int z = posZ + dz[i];
			int y = posY + dy[i];
			int x = posX + dx[i];
			if (z == h || y == n || x == m || x < 0 || y < 0 || z < 0 ||
				tomato[z][y][x] != 0) continue;

			tomato[z][y][x] = 1;
			q.push(make_pair(z * (m * n) + y * m + x, days + 1));
			s--;
		}
	}
}
int main()
{
	cin >> m >> n >> h;
	tomato.resize(h, vector<vector<int>>(n, vector<int>(m)));

	for (int i = 0; i < n * h; i++)
		for (int j = 0; j < m; j++)
		{
			cin >> tomato[i / n][i % n][j];
			if (tomato[i / n][i % n][j] == 0) s++;
		}


	bfs();
	cout << ans << endl;
}

// https://www.acmicpc.net/problem/7569

/*
Little complex bfs problem.
Don't ignore z direction.
*/