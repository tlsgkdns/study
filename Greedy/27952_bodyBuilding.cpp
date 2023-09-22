#include <iostream>

using namespace std;
using ll = long long;
ll S = 0, N, A[500002], B, ans = 0, X;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> X;
	for (int i = 0; i < N; i++) cin >> A[i];
	for (int i = 0; i < N; i++)
	{
		cin >> B;
		S += B;
		if (A[i] > S) ans = -1;
	}
	if (ans >= 0) ans = (S - A[N - 1]) / X;
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/27952