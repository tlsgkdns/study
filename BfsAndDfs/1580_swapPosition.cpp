#include <queue>
#include <iostream>
#include <cstring>
using namespace std;

int v[21][21][21][21], N, M, ay, ax, by, bx;
char w;
bool W[21][21];
int dy[9] = { -1, -1, -1, 0, 0, 1, 1, 1, 0 };
int dx[9] = { -1, 0, 1, -1, 1, -1, 0, 1, 0 };
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
		{
			cin >> w;
			if (w == 'A')
			{
				ay = i;
				ax = j;
				W[i][j] = true;
			}
			else if (w == 'B')
			{
				by = i;
				bx = j;
				W[i][j] = true;
			}
			else if (w == '.')
			{
				W[i][j] = true;
			}
			else
				W[i][j] = false;
		}
	queue<pair<pair<int, int>, pair<int, int>>> q;
	q.push({ {ay, ax}, {by, bx} });
	v[ay][ax][by][bx] = 0;
	while (!q.empty())
	{
		int ar = q.front().first.first;
		int ac = q.front().first.second;
		int br = q.front().second.first;
		int bc = q.front().second.second;
		q.pop();
		for (int da = 0; da < 9; da++)
		{
			int nar = ar + dy[da];
			int nac = ac + dx[da];
			if (!inRange(nar, nac) || !W[nar][nac]) continue;
			for (int db = 0; db < 9; db++)
			{

				int nbr = br + dy[db];
				int nbc = bc + dx[db];
				if (!inRange(nbr, nbc) || !W[nbr][nbc]) continue;
				if (nar == br && nac == bc && nbr == ar && nbc == ac) continue;
				if (nar == nbr && nac == nbc) continue;
				if (v[nar][nac][nbr][nbc] >= 0) continue;
				v[nar][nac][nbr][nbc] = v[ar][ac][br][bc] + 1;
				q.push({ {nar, nac}, {nbr, nbc} });
			}
		}
	}
	cout << v[by][bx][ay][ax] << '\n';
}

// https://www.acmicpc.net/problem/1580