#include <iostream>
#include <algorithm>
using namespace std;
int N, A[1000001], L[1000001], R[1000001];

int gcd(int a, int b)
{
	if (a > b) swap(a, b);
	while (a > 0)
	{
		int tmp = b % a;
		b = a;
		a = tmp;
	}
	return b;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++) cin >> A[i];
	L[0] = A[0]; R[N - 1] = A[N - 1];
	for (int i = 1; i < N; i++) L[i] = gcd(L[i - 1], A[i]);
	for (int i = N - 2; i >= 0; i--) R[i] = gcd(R[i + 1], A[i]);
	int ans1 = R[0], ans2 = -1;
	for (int i = 0; i < N; i++)
	{
		int g = ((i == 0) ? R[i + 1] : ((i == N - 1) ? L[i - 1] : gcd(R[i + 1], L[i - 1])));
		if (g > ans1)
		{
			ans1 = g;
			ans2 = i;
		}
	}
	if (ans2 < 0) cout << -1 << '\n';
	else cout << ans1 << " " << A[ans2] << '\n';
}

// https://www.acmicpc.net/problem/14476