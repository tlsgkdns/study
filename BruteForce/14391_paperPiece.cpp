#include <iostream>

using namespace std;

char ch;
int N, M, G[5][5], ans = 0, P[5];

void solve2()
{
	int ret = 0;
	for (int i = 0; i < N; i++)
	{
		int s = 0;
		for (int j = 0; j < M; j++)
		{
			if (P[i] & (1 << j))
			{
				s *= 10;
				s += G[i][j];
			}
			else
			{
				ret += s;
				s = 0;
			}
		}
		ret += s;
	}
	for (int j = 0; j < M; j++)
	{
		int s = 0;
		for (int i = 0; i < N; i++)
		{
			if (!(P[i] & (1 << j)))
			{
				s *= 10;
				s += G[i][j];
			}
			else
			{
				ret += s;
				s = 0;
			}
		}
		ret += s;
	}
	ans = max(ret, ans);
}
void solve(int idx)
{
	if (idx == N)
	{
		solve2();
		return;
	}
	for (int n = 0; n < (1 << M); n++)
	{
		P[idx] = n;
		solve(idx + 1);
		P[idx] = 0;
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
		{
			cin >> ch;
			G[i][j] = (ch - '0');
		}
	solve(0);
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/14391