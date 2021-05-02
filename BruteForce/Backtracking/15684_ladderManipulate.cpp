#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int INF = 1000000000;
int N, M, H, a, b;
vector<vector<bool>> ladder;
int goDown(int s)
{
	int line = s;
	for (int i = 0; i < H; i++)
		for (int d = -1; d <= 0; d++)
		{
			int nxt = line + d;
			if (nxt < 0 || nxt >= N - 1) continue;
			if (ladder[i][nxt])
			{
				if (d == 0) line++;
				else line--;
				break;
			}
		}
	return line;
}
bool allClean()
{
	for (int l = 0; l < N; l++)
		if (l != goDown(l))
			return false;
	return true;
}
int solve(int added, int si, int sj)
{
	if (added > 3) return INF;
	if (allClean()) return added;
	int ret = INF;
	for (int i = si; i < H; i++)
		for (int j = sj; j < N - 1; j++)
		{
			if (ladder[i][j]) continue;
			if (j - 1 >= 0 && ladder[i][j - 1]) continue;
			if (j + 1 < N - 1 && ladder[i][j + 1]) continue;
			ladder[i][j] = true;
			if (j == 0)
				ret = min(ret, solve(added + 1, i, j));
			else
				ret = min(ret, solve(added + 1, i, j - 1));
			ladder[i][j] = false;
		}
	return ret;
}
int main()
{
	cin >> N >> M >> H;
	ladder.resize(H, vector<bool>(N - 1, false));
	for (int i = 0; i < M; i++)
	{
		cin >> a >> b;
		ladder[a - 1][b - 1] = true;
	}
	int ans = solve(0, 0, 0);
	if (ans == INF) cout << -1 << '\n';
	else cout << ans << '\n';
}

//https://www.acmicpc.net/problem/15684