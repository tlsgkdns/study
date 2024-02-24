#include <iostream>

using namespace std;

int N, A[3], ans = 0;
void solve(int idx, int n)
{
	if (n == 0)
	{
		ans = 1;
		return;
	}
	if (idx == 2)
	{
		if (n % A[idx] == 0) ans = 1;
		return;
	}
	if (A[idx] <= n) solve(idx, n - A[idx]);
	solve(idx + 1, n);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	for (int i = 0; i < 3; i++) cin >> A[i];
	cin >> N;
	solve(0, N);
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/14697
