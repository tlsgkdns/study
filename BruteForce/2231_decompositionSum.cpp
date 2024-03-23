#include <iostream>
#include <algorithm>
using namespace std;

int N, ans = 1000000007;

void solve(int s, int n)
{
	if (s > N) return;
	if (s == N)
	{
		ans = min(ans, n);
		return;
	}
	for (int i = 0; i <= 9; i++)
	{
		int now = n * 10 + i;
		solve(s - n + now + i, now);
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 1; i <= 9; i++) solve(i + i, i);
	if (ans == 1000000007) ans = 0;
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/2231