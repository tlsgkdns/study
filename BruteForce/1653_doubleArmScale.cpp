#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;
using ll = long long;
ll ans = 0, s = 0;
int S[10], N, K, cnt = 0, w = 0, b = 0;
void solve(int idx)
{
	if (cnt > K || w < 0) return;
	if (idx >= 10)
	{
		if (w == 0)
		{
			ans = s;
			++cnt;
		}
		return;
	}
	int c = 0, tw = 0;
	if (idx == 5)
	{
		for (int i = N - 1; i >= 0; i--)
		{
			if (b & (1 << i)) continue;
			tw += ((5 - c) * S[i]);
			++c;
		}
		if (tw < w) return;
	}
	solve(idx + 1);
	ll tmps = s;
	int tmpw = w;
	for (int i = 0; i < N; i++)
	{
		if (b & (1 << i)) continue;
		b |= (1 << i);
		s += S[i] * pow(10, 10 - idx - 1);
		w = (idx > 4) ? w - ((idx - 4) * S[i]) : w + ((5 - idx) * S[i]);
		solve(idx + 1);
		b ^= (1 << i);
		s = tmps;
		w = tmpw;
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> S[i];
	cin >> K;
	solve(0);
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/1653