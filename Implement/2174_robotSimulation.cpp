#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int land[101][101], dir[101];
pair<int, int> pos[101];
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };
int A, B, N, M, X, Y, cnt, num;
char D, cmd;
bool inRange(int y, int x)
{
	return y > 0 && x > 0 && y <= B && x <= A;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	memset(land, 0, sizeof(land));
	cin >> A >> B;
	cin >> N >> M;
	for (int n = 1; n <= N; n++)
	{
		cin >> X >> Y >> D;
		land[X][Y] = n; pos[n] = { X, Y };
		if (D == 'N') dir[n] = 0;
		if (D == 'E') dir[n] = 1;
		if (D == 'S') dir[n] = 2;
		if (D == 'W') dir[n] = 3;
	}
	string ans = "OK\n";
	for (int i = 0; i < M; i++)
	{
		cin >> num >> cmd >> cnt;
		if (cmd == 'R')
			for (int c = 0; c < cnt; c++)
				dir[num] = (dir[num] + 1) % 4;
		else if (cmd == 'L')
			for (int c = 0; c < cnt; c++)
				dir[num] = (dir[num] + 3) % 4;
		else
		{
			for (int c = 0; c < cnt; c++)
			{
				int ny = pos[num].second + dy[dir[num]];
				int nx = pos[num].first + dx[dir[num]];
				if (!inRange(ny, nx))
				{
					if (ans == "OK\n")
						ans = "Robot " + to_string(num) + " crashes into the wall\n";
					else
						break;
				}
				else if (land[nx][ny] != 0)
				{
					if (ans == "OK\n")
						ans = "Robot " + to_string(num) + " crashes into robot " + to_string(land[nx][ny]) + '\n';
					else
						break;
				}
				else
				{
					land[nx][ny] = num;
					land[pos[num].first][pos[num].second] = 0;
					pos[num] = { nx, ny };
				}
			}
		}
	}
	cout << ans;
}

// https://www.acmicpc.net/problem/2174