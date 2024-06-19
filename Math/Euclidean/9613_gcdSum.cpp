#include <iostream>

using namespace std;
using ll = long long;
int N, T, A[101];

ll gcd(int a, int b)
{
	if (b == 0) return a;
	if (b > a) return gcd(b, a);
	return gcd(b, a % b);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> T;
	while (T--)
	{
		ll ans = 0;
		cin >> N;
		for (int i = 0; i < N; i++) cin >> A[i];
		for (int i = 0; i < N; i++)
			for (int j = i + 1; j < N; j++)
				ans += gcd(A[i], A[j]);
		cout << ans << '\n';
	}
}

// https://www.acmicpc.net/problem/9613