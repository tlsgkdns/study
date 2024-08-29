#include <iostream>

using namespace std;

int N, M, G[25][25], ans = 0;

bool check()
{
	for (int i = 0; i < N - 1; i++)
		for (int j = 0; j < M - 1; j++)
			if (G[i][j] && G[i + 1][j] && G[i][j + 1] && G[i + 1][j + 1])
				return false;
	return true;
}
void solve(int idx)
{
	if (idx == N * M)
	{
		ans += check();
		return;
	}
	int y = idx / M;
	int x = idx % M;
	solve(idx + 1);
	G[y][x] = 1;
	solve(idx + 1);
	G[y][x] = 0;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	solve(0);
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/14712