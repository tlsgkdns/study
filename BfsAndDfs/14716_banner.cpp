#include <iostream>

using namespace std;

bool v[251][251], A[251][251];
int ans = 0, M, N;
int dy[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int dx[8] = { -1, 1, 0, -1, 1, -1, 1, 0 };
bool inRange(int y, int x)
{
	return y >= 0 && x >= 0 && y < M && x < N;
}
void solve(int y, int x)
{
	for (int d = 0; d < 8; d++)
	{
		int ny = y + dy[d];
		int nx = x + dx[d];
		if (!inRange(ny, nx) || v[ny][nx] || !A[ny][nx]) continue;
		v[ny][nx] = true;
		solve(ny, nx);
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> M >> N;
	for (int i = 0; i < M; i++)
		for (int j = 0; j < N; j++)
			cin >> A[i][j];
	for (int i = 0; i < M; i++)
		for (int j = 0; j < N; j++)
			if (A[i][j] && !v[i][j])
			{
				v[i][j] = true;
				++ans;
				solve(i, j);
			}
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/14716