#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
int N, M, K;
string Q;
unordered_map<string, int> um;
vector<string> dp[11][11][5];
char G[11][11];
int dy[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int dx[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };
vector<string>& solve(int y, int x, int l)
{
	vector<string>& ret = dp[y][x][l];
	if (!ret.empty()) return ret;
	if (l == 1)
	{
		string tmp = "";
		tmp.push_back(G[y][x]);
		ret.push_back(tmp);
		return ret;
	}
	for (int d = 0; d < 8; d++)
	{
		int ny = y + dy[d];
		int nx = x + dx[d];
		ny = (ny < 0) ? N - 1 : ny; nx = (nx < 0) ? M - 1 : nx;
		ny = (ny == N) ? 0 : ny; nx = (nx == M) ? 0 : nx;
		vector<string>& tmp = solve(ny, nx, l - 1);
		for (int i = 0; i < tmp.size(); i++)
			ret.push_back(tmp[i] + G[y][x]);
	}
	return ret;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M >> K;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> G[i][j];
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			for (int k = 1; k <= 5; k++)
				solve(i, j, k);
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			for (int k = 1; k <= 5; k++)
				for (int idx = 0; idx < dp[i][j][k].size(); idx++)
					++um[dp[i][j][k][idx]];
	while (K--)
	{
		cin >> Q;
		cout << um[Q] << '\n';
	}
}

// https://www.acmicpc.net/problem/20166