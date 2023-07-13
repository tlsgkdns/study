#include <iostream>
#include <algorithm>
using namespace std;

int N, A[10001], ans = 0;

void solve(int idx)
{
	if (idx == N) return;
	if (A[idx] == 0)
	{
		solve(idx + 1);
		return;
	}
	int mode = 0;
	if (idx < N - 1 && A[idx + 1] > 0) mode = 1;
	if (mode == 1 && idx < N - 2 && A[idx + 2] > 0) mode = 2;
	if (mode == 0)
	{
		ans += A[idx] * 3;
		A[idx] = 0;
		solve(idx + 1);
	}
	else if (mode == 1)
	{
		int a = min(A[idx], A[idx + 1]);
		A[idx] -= a; A[idx + 1] -= a;
		ans += a * 5;
		solve(idx);
	}
	else
	{
		int a = 0;
		if (A[idx + 1] > A[idx + 2])
		{
			a = min(A[idx + 1] - A[idx + 2], A[idx]);
			A[idx] -= a; A[idx + 1] -= a;
			ans += a * 5;
			solve(idx);
		}
		else
		{
			a = min(A[idx], min(A[idx + 1], A[idx + 2]));
			A[idx] -= a; A[idx + 1] -= a; A[idx + 2] -= a;
			ans += a * 7;
			solve(idx);
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++) cin >> A[i];
	solve(0);
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/18185