#include <iostream>
using namespace std;
int A[10], ans = 0;

void solve(int idx, int fir, int sec, int score)
{
	if (idx == 10)
	{
		ans += (score >= 5);
		return;
	}
	for (int i = 1; i <= 5; i++)
	{
		if (fir == sec && i == fir) continue;
		solve(idx + 1, i, fir, score + (A[idx] == i));
	}
}
int main()
{
	for (int i = 0; i < 10; i++) cin >> A[i];
	solve(0, 0, 0, 0);
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/19949