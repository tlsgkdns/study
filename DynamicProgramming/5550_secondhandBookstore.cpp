#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

int dp[11][2001], N, K;
int C, G, A[2001];
vector<pair<int, int>> arr;
vector<int> B[11], acc[11];

int solve(int idx, int cnt)
{
	if (idx == 11) return 0;
	int& ret = dp[idx][cnt];
	if (ret >= 0) return ret;
	ret = max(ret, solve(idx + 1, cnt));
	for (int i = 0; i < min(cnt, (int)acc[idx].size()); i++)
		ret = max(ret, solve(idx + 1, cnt - i - 1) + acc[idx][i] + ((i + 1) * i));
	return ret;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	memset(dp, -1, sizeof(dp));
	cin >> N >> K;
	for (int i = 0; i < N; i++)
	{
		cin >> C >> G;
		B[G].push_back(C);
	}
	for (int i = 1; i <= 10; i++) sort(B[i].begin(), B[i].end(), greater<int>());
	for (int i = 1; i <= 10; i++)
		for (int idx = 0; idx < B[i].size(); idx++)
		{
			if (acc[i].empty()) acc[i].push_back(B[i][idx]);
			else acc[i].push_back(acc[i].back() + B[i][idx]);
		}
	cout << solve(1, K) << '\n';
}

// https://www.acmicpc.net/problem/5550