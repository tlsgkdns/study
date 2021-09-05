#include <iostream>
#include <vector>
using namespace std;

int N, M, d, s, ans = 0;
vector<vector<int>> water;
vector<vector<bool>> cloud;
int dy[9] = { 0, 0, -1, -1, -1, 0, 1, 1, 1 };
int dx[9] = { 0, -1, -1, 0, 1, 1, 1, 0, -1 };
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	water.resize(N, vector<int>(N));
	cloud.resize(N, vector<bool>(N));
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{
			cin >> water[i][j];
			ans += water[i][j];
		}
	cloud[N - 1][0] = cloud[N - 1][1] = cloud[N - 2][0] = cloud[N - 2][1] = true;
	for (int m = 0; m < M; m++)
	{
		cin >> d >> s;
		water;
		s %= N;
		vector<vector<bool>> tmp(N, vector<bool>(N, false));
		for (int y = 0; y < N; y++)
			for (int x = 0; x < N; x++)
			{
				if (!cloud[y][x]) continue;
				int ny = y + dy[d] * s;
				int nx = x + dx[d] * s;
				ny = (ny + N) % N;
				nx = (nx + N) % N;
				tmp[ny][nx] = true;
				water[ny][nx]++;
				ans++;
			}
		for (int y = 0; y < N; y++)
			for (int x = 0; x < N; x++)
			{
				if (!tmp[y][x]) continue;
				for (int n = 2; n <= 8; n += 2)
				{
					int ny = y + dy[n];
					int nx = x + dx[n];
					if (ny < 0 || nx < 0 || ny >= N || nx >= N || water[ny][nx] == 0) continue;
					water[y][x]++;
					ans++;
				}
			}
		cloud = vector<vector<bool>>(N, vector<bool>(N, false));
		for (int y = 0; y < N; y++)
			for (int x = 0; x < N; x++)
			{
				if (water[y][x] < 2 || tmp[y][x]) continue;
				cloud[y][x] = true;
				water[y][x] -= 2;
				ans -= 2;
			}
	}
	cout << ans << '\n';
}
// https://www.acmicpc.net/problem/21610