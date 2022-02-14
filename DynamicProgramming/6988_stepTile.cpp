#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
using ll = long long;
vector<ll> tile;
vector<vector<ll>> dp;
ll N, lm = 0, ans = 0;
ll v[1000001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	memset(v, -1, sizeof(v));
	cin >> N;
	dp.resize(N, vector<ll>(N, 0));
	tile.resize(N);
	for (int i = 0; i < N; i++)
	{
		cin >> tile[i];
		lm = max(tile[i], lm);
		v[tile[i]] = i;
	}
	for (int y = N - 1; y >= 0; y--)
		for (int x = y - 1; x >= 0; x--)
		{
			int step = tile[y] - tile[x];
			ll nxt = step + tile[y];
			if (nxt > lm || v[nxt] == -1)
			{
				dp[x][y] = tile[y] + tile[x];
				continue;
			}
			dp[x][y] = dp[y][v[nxt]] + tile[x];
			ans = max(ans, dp[x][y]);
		}
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/6988