#include <iostream>

using namespace std;
using ll = long long;
ll D, K, F[31];
bool f = false;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> D >> K;
	int L = K / D;
	F[0] = 1; F[1] = 1;
	for (int i = 2; i <= D; i++) F[i] = F[i - 1] + F[i - 2];
	for (ll a = 1; a <= L; a++)
	{
		ll b = (K - F[D - 3] * a) / F[D - 2];
		if (F[D - 3] * a + F[D - 2] * b == K)
		{
			cout << a << '\n' << b << '\n';
			break;
		}
	}
}

// https://www.acmicpc.net/problem/2502