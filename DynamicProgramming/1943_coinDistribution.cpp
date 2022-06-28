#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int N;
int dp[100001][101];
bool v[50001];
int cnt[101], val[101];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	for (int t = 0; t < 3; t++)
	{
		memset(v, false, sizeof(v));
		memset(dp, 0, sizeof(dp));
		cin >> N;
		queue<int> q;
		int S = 0;
		for (int i = 0; i < N; i++)
		{
			cin >> val[i] >> cnt[i];
			q.push(val[i]);
			dp[val[i]][i] = 1;
			v[val[i]] = true;
			S += val[i] * cnt[i];
		}
		if (S % 2 == 1) S = 1000000000;
		S /= 2;
		int ans = 0;
		while (!q.empty())
		{
			int now = q.front();
			q.pop();
			if (now == S)
			{
				ans = 1;
				break;
			}
			for (int i = 0; i < N; i++)
			{
				int nxt = now + val[i];
				if (dp[now][i] >= cnt[i] || nxt > 50000 || v[nxt]) continue;
				v[nxt] = true;
				for (int j = 0; j < N; j++) dp[nxt][j] = dp[now][j];
				dp[nxt][i]++;
				q.push(nxt);
			}
		}
		cout << ans << '\n';
	}
}

// https://www.acmicpc.net/problem/1943