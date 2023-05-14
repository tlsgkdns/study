#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
using ll = long long;

const ll INF = 10000000000001;
pair<int, int> pos[100001];
int dy[5] = { 0, 0, 0, -1, 1 };
int dx[5] = { 0, -1, 1, 0, 0 };
ll dp[100001][6];
int N;
ll solve(int idx, int d)
{
	if (idx == N) return 0;
	ll& ret = dp[idx][d];
	if (ret >= 0) return ret;
	int y = pos[idx].first + dy[d];
	int x = pos[idx].second + dx[d];
	ret = INF;
	for (int i = 0; i < 5; i++)
	{
		int ny = pos[idx + 1].first + dy[i];
		int nx = pos[idx + 1].second + dx[i];
		if (ny < 0 || nx < 0 || ny >= 100001 || nx >= 100001) continue;
		ret = min(ret, solve(idx + 1, i) + abs(y - ny) + abs(x - nx));
	}
	return ret;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	memset(dp, -1, sizeof(dp));
	cin >> N;
	for (int i = 0; i <= N; i++)
		cin >> pos[i].first >> pos[i].second;
	cout << solve(0, 0) << '\n';
}

// https://www.acmicpc.net/problem/2159