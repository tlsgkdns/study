#include <iostream>

using namespace std;

int A[4], P[101], L, R, ans = 0;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> A[1] >> A[2] >> A[3];
	for (int i = 0; i < 3; i++)
	{
		cin >> L >> R;
		for (int p = L; p < R; p++)
			P[p]++;
	}
	A[2] *= 2; A[3] *= 3;
	for (int i = 1; i <= 100; i++)
		ans += A[P[i]];
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/2979