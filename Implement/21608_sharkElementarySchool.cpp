#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int N, num;
vector<vector<int>> classroom;
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };

struct Seat
{
	int y, x;
	int pref, vacant;
	Seat(int _y, int _x, int _p, int _v)
	{
		y = _y; x = _x; pref = _p; vacant = _v;
	}
};
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	classroom.resize(N * N, vector<int>(N * N, -1));
	vector<vector<int>> like(N * N + 1, vector<int>(4));
	for (int qw = 0; qw < N * N; qw++)
	{
		cin >> num;
		cin >> like[num][0] >> like[num][1] >> like[num][2] >> like[num][3];
		Seat seat(0, 0, -1, -1);
		for (int r = 0; r < N; r++)
			for (int c = 0; c < N; c++)
			{
				if (classroom[r][c] != -1) continue;
				int p = 0, v = 0;
				for (int d = 0; d < 4; d++)
				{
					int nr = dy[d] + r;
					int nc = dx[d] + c;
					if (nr < 0 || nc < 0 || nr >= N || nc >= N) continue;
					if (classroom[nr][nc] == -1)
					{
						v++;
						continue;
					}
					for (int i = 0; i < 4; i++)
						if (like[num][i] == classroom[nr][nc])
							p++;
				}
				if (seat.pref < p)
					seat = Seat(r, c, p, v);
				else if (seat.pref == p && seat.vacant < v)
					seat = Seat(r, c, p, v);
			}
		classroom[seat.y][seat.x] = num;
	}
	int ans = 0;
	for (int y = 0; y < N; y++)
		for (int x = 0; x < N; x++)
		{
			int sat = 0;
			for (int d = 0; d < 4; d++)
			{
				int ny = dy[d] + y;
				int nx = dx[d] + x;
				if (ny < 0 || nx < 0 || ny >= N || nx >= N) continue;
				for (int c = 0; c < 4; c++)
					if (like[classroom[y][x]][c] == classroom[ny][nx])
						sat++;
			}
			if (sat == 0) continue;
			ans += pow(10, sat - 1);
		}
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/21608