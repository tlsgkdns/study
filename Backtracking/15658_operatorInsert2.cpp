#include <iostream>
#include <algorithm>

using namespace std;
int N, A[12], C[4], ans1 = -1e9, ans2 = 1e9;

void solve(int n, int idx)
{
	if (idx == N)
	{
		ans1 = max(ans1, n);
		ans2 = min(ans2, n);
		return;
	}
	if (C[0] > 0)
	{
		C[0]--;
		solve(n + A[idx], idx + 1);
		C[0]++;
	}
	if (C[1] > 0)
	{
		C[1]--;
		solve(n - A[idx], idx + 1);
		C[1]++;
	}
	if (C[2] > 0)
	{
		C[2]--;
		solve(n * A[idx], idx + 1);
		C[2]++;
	}
	if (C[3] > 0)
	{
		C[3]--;
		solve(n / A[idx], idx + 1);
		C[3]++;
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++) cin >> A[i];
	for (int i = 0; i < 4; i++) cin >> C[i];
	solve(A[0], 1);
	cout << ans1 << '\n' << ans2 << '\n';
}

// https://www.acmicpc.net/problem/15658