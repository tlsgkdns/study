#include <iostream>
#include <algorithm>
using namespace std;

int N, L, R, X, A[16], ans = 0;
void solve(int idx, int easy, int hard, int score, int cnt)
{
	if (score > R) return;
	if (idx == N)
	{
		ans += (score >= L && easy + X <= hard && cnt >= 2);
		return;
	}
	solve(idx + 1, easy, hard, score, cnt);
	solve(idx + 1, min(easy, A[idx]), max(hard, A[idx]), score + A[idx], cnt + 1);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> L >> R >> X;
	for (int i = 0; i < N; i++)cin >> A[i];
	solve(0, 1000000007, -1, 0, 0);
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/16938