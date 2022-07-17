#include <iostream>
#include <algorithm>
using namespace std;

int N, S[8], W[8], ans = 0;

void solve(int idx, int d)
{
	ans = max(ans, d);
	if (idx == N)
		return;
	if (S[idx] <= 0)
	{
		solve(idx + 1, d);
		return;
	}
	for (int i = 0; i < N; i++)
	{
		if (idx == i || S[i] <= 0) continue;
		S[idx] -= W[i];
		S[i] -= W[idx];
		solve(idx + 1, d + (S[idx] <= 0) + (S[i] <= 0));
		S[idx] += W[i];
		S[i] += W[idx];
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++) cin >> S[i] >> W[i];
	solve(0, 0);
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/16987