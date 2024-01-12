#include <iostream>
#include <algorithm>
using namespace std;

int N, ans = 0;
int v[21];
char C;

void solve(int idx)
{
	if (idx == N)
	{
		int s = 0;
		for (int j = 0; j < N; j++)
		{
			int n = 0;
			for (int i = 0; i < N; i++)
				if ((v[i] & (1 << j)))
					++n;
			if (N - n < n) n = N - n;
			s += n;
		}
		ans = min(ans, s);
		return;
	}
	v[idx] = ((1 << N) - 1) ^ v[idx];
	solve(idx + 1);
	v[idx] = ((1 << N) - 1) ^ v[idx];
	solve(idx + 1);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int n = 0;
		for (int j = 0; j < N; j++)
		{
			cin >> C;
			if (C == 'T')
			{
				n |= (1 << j);
				++ans;
			}
		}
		v[i] = n;
	}
	solve(0);
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/1285