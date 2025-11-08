#include <iostream>

using namespace std;

int N, A[500001], X;
double S = 0, cnt = 0;
int gcd(int a, int b)
{
	if (a < b) return gcd(b, a);
	if (b == 0) return a;
	return gcd(b, a % b);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++) cin >> A[i];
	cin >> X;
	for (int i = 0; i < N; i++)
	{
		int g = gcd(X, A[i]);
		if (g == 1)
		{
			S += A[i];
			++cnt;
		}
	}
	cout << fixed; cout.precision(7);
	cout << S / cnt << '\n';
}

// https://www.acmicpc.net/problem/21920