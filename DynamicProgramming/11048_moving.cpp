#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
vector<vector<int>> dp, m;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	dp.resize(N, vector<int>(M, 0));
	m.resize(N, vector<int>(M));
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> m[i][j];
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
		{
			if (i == 0 && j == 0) dp[i][j] = m[i][j];
			else if (i == 0) dp[i][j] = dp[i][j - 1] + m[i][j];
			else if (j == 0) dp[i][j] = dp[i - 1][j] + m[i][j];
			else dp[i][j] = dp[i][j] = max(dp[i - 1][j], max(dp[i - 1][j - 1], dp[i][j - 1])) + m[i][j];
		}
	cout << dp[N - 1][M - 1] << '\n';
}
// https://www.acmicpc.net/problem/11048