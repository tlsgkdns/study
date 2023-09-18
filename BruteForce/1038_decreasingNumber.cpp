#include <iostream>

using namespace std;
using ll = long long;
int cnt = 0, N;
ll ans = -1;
void solve(int idx, int d, int prev, ll num)
{
	if (ans >= 0) return;
	if (idx == d)
	{
		if (cnt == N)
		{
			ans = num;
			return;
		}
		++cnt;
		return;
	}
	for (int n = d - idx - 1; n < prev; n++)
		solve(idx + 1, d, n, num * 10 + n);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int d = 1; d <= 10; d++)
	{
		if (ans >= 0) break;
		solve(0, d, 10, 0);
	}
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/1038