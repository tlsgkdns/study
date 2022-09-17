#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;
int dp[10001], coin[101];
int N, K;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	memset(dp, -1, sizeof(dp));
	cin >> N >> K;
	for (int i = 0; i < N; i++) cin >> coin[i];
	queue<int> q;
	q.push(0); dp[0] = 0;
	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		for (int idx = 0; idx < N; idx++)
		{
			int nxt = cur + coin[idx];
			if (nxt > K || dp[nxt] >= 0) continue;
			dp[nxt] = dp[cur] + 1;
			q.push(nxt);
		}
	}
	cout << dp[K] << '\n';
}

// https://www.acmicpc.net/problem/2294