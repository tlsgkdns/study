#include <iostream>
#include <cstdio>
using namespace std;
using ll = long long;
string M;
ll N, K, Y = 0, X = 0;
ll ans = 1;
ll getSum(ll n)
{
	return (n * (n + 1)) / 2;
}
ll getVal(int y, int x)
{
	ll n = y + x;
	if (n >= N) return N * N + 1 - getVal(N - y - 1, N - x - 1);
	if (n % 2 == 0)
		return getSum(n) + x + 1;
	else
		return getSum(n) + y + 1;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> K;
	cin >> M;
	for (int i = 0; i < K; i++)
	{
		switch (M[i])
		{
		case 'D':
			ans += getVal(++Y, X);
			break;
		case 'R':
			ans += getVal(Y, ++X);
			break;
		case 'U':
			ans += getVal(--Y, X);
			break;
		case 'L':
			ans += getVal(Y, --X);
			break;
		}
	}
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/3101