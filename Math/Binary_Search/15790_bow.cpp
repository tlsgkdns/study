#include <iostream>

using namespace std;

int N, M, X[100001], K, ans = -1;

bool solve(int L, int st)
{
	int cnt = 0, prv = st;
	for (int i = 1; i <= M; i++)
	{
		int now = (i + st) % (M + 1);
		if (X[now] >= X[prv] + L)
		{
			++cnt;
			prv = now;
		}
	}
	return cnt >= K;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(NULL); cin.tie(NULL);
	cin >> N >> M >> K;
	for (int i = 0; i < M; i++) cin >> X[i];
	X[M] = N + X[0];
	for (int s = 0; s < M; s++)
	{
		int l = -1, r = N + 1;
		X[M] = N + X[s];
		while (l + 1 < r)
		{
			int m = (l + r) / 2;
			if (solve(m, s)) l = m;
			else r = m;
		}
		if (ans < l) ans = l;
	}
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/15790