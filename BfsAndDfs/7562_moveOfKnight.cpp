#include <iostream>
#include <queue>

using namespace std;

int dy[8] = { -1, -1, 1, 1, -2, -2, 2, 2 };
int dx[8] = { 2, -2, 2, -2, 1, -1, 1, -1 };
queue<int> ans;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int t;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		pair<int, int> src, dst;
		int L;
		cin >> L;
		cin >> src.first >> src.second;
		cin >> dst.first >> dst.second;
		vector<vector<int>> v(L, vector<int>(L, -1));
		queue<pair<int, int>> q;
		q.push(src);
		v[src.first][src.second] = 0;
		while (!q.empty())
		{
			pair<int, int> cur = q.front();
			q.pop();
			if (cur == dst) break;
			for (int d = 0; d < 8; d++)
			{
				int ny = cur.first + dy[d];
				int nx = cur.second + dx[d];
				if (ny < 0 || nx < 0 || ny >= L || nx >= L
					|| v[ny][nx] != -1) continue;
				v[ny][nx] = v[cur.first][cur.second] + 1;
				q.push(make_pair(ny, nx));
			}
		}
		v;
		ans.push(v[dst.first][dst.second]);
	}
	while (!ans.empty())
	{
		cout << ans.front() << '\n';
		ans.pop();
	}
}
// https://www.acmicpc.net/problem/7562