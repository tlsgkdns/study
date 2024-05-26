#include <iostream>
#include <algorithm>
using namespace std;

int ans, A[51], N, V;
bool v[51][1001][1001];


void solve(int idx, int mn, int mx, int cnt)
{
	if (v[idx][mn][mx]) return;
	v[idx][mn][mx] = true;
	if (cnt >= ans) return;
	if (mx - mn >= V)
	{
		ans = min(ans, cnt);
		return;
	}
	if (idx + 2 < N)
	{
		int nmn = min(mn, A[idx + 2]);
		int nmx = max(mx, A[idx + 2]);
		solve(idx + 2, nmn, nmx, cnt + 1);
	}
	if (idx + 1 < N)
	{
		int nmn = min(mn, A[idx + 1]);
		int nmx = max(mx, A[idx + 1]);
		solve(idx + 1, nmn, nmx, cnt + 1);
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> V;
	for (int i = 0; i < N; i++) cin >> A[i];
	ans = N;
	solve(0, A[0], A[0], 1);
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/1332