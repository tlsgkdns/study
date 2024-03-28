#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int N, S[11], B[11], ans = 1000000007;

void solve(int idx, int s, int b, bool f)
{
	if (idx == N)
	{
		if (f) ans = min(ans, abs(s - b));
		return;
	}
	solve(idx + 1, s, b, f);
	if (f)
		solve(idx + 1, s * S[idx], b + B[idx], true);
	else
		solve(idx + 1, S[idx], B[idx], true);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++) cin >> S[i] >> B[i];
	solve(0, 0, 0, false);
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/2961