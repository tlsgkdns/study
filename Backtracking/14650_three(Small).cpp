#include <iostream>

using namespace std;
using ll = long long;
int cnt = 0, N, ans = 0;
ll n = 0;
void solve()
{
	if (cnt == N)
	{
		if (n > 0 && n % 3 == 0) ++ans;
		return;
	}
	++cnt;
	if (n > 0)
	{
		n *= 10;
		solve();
		n /= 10;
	}
	n = n * 10 + 1;
	solve();
	n /= 10;
	n = n * 10 + 2;
	solve();
	n /= 10;
	--cnt;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	solve();
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/14650