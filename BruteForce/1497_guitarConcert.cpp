#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;
const int INF = 1000000007;
ll D[12];
int N, M, P = 0, ans = INF;
string S1, S2;
void solve(int idx, int cnt, ll s)
{
	if (idx >= N)
	{
		int c = 0;
		for (ll d = 1; d <= s; d <<= 1)
			if (s & d)
				++c;
		if (c > 0)
		{
			if (c == P) ans = min(ans, cnt);
			else if (c > P)
			{
				ans = cnt;
				P = c;
			}
		}
		return;
	}
	solve(idx + 1, cnt, s);
	solve(idx + 1, cnt + 1, s | D[idx]);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		cin >> S1 >> S2;
		ll s = 0;
		for (ll idx = 0; idx < S2.size(); idx++)
			if (S2[idx] == 'Y')
				s |= (1LL << idx);
		D[i] = s;
	}
	solve(0, 0, 0);
	if (P == 0) ans = -1;
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/1497