#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
const int MAX = 200002;
int N, K, v[MAX], ans = -1, cnt = 0, dp[MAX];
queue<int> q;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	memset(v, -1, sizeof(v));
	cin >> N >> K;
	v[N] = 0;
	q.push(N);
	dp[N] = 1;
	while (!q.empty())
	{
		int here = q.front();
		q.pop();
		if (here == K)
		{
			ans = v[here];
			break;
		}
		if (here - 1 >= 0)
		{
			if (v[here - 1] < 0 || v[here - 1] == v[here] + 1)
				dp[here - 1] += dp[here];
			if (v[here - 1] < 0)
			{
				v[here - 1] = v[here] + 1;
				q.push(here - 1);
			}
		}
		if (here + 1 < MAX)
		{
			if (v[here + 1] < 0 || v[here + 1] == v[here] + 1)
				dp[here + 1] += dp[here];
			if (v[here + 1] < 0)
			{
				v[here + 1] = v[here] + 1;
				q.push(here + 1);
			}
		}
		if (2 * here < MAX)
		{
			if (v[2 * here] < 0 || v[2 * here] == v[here] + 1)
				dp[2 * here] += dp[here];
			if (v[2 * here] < 0)
			{
				v[2 * here] = v[here] + 1;
				q.push(2 * here);
			}
		}
	}
	cout << v[K] << '\n' << dp[K] << '\n';
}

// https://www.acmicpc.net/problem/12851