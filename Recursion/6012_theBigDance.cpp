#include <iostream>

using namespace std;

int N, ans = 0;

void solve(int l, int r)
{
	if (r - l <= 0) return;
	if (r - l == 1)
	{
		ans += (l * r);
		return;
	}
	int m = (l + r) / 2;
	solve(l, m); solve(m + 1, r);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(NULL); cin.tie(NULL);
	cin >> N;
	solve(1, N);
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/6012