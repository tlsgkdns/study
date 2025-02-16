#include <iostream>

using namespace std;
using ll = long long;
ll N, P, ans = 1;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> P;
	for (ll i = 1; i <= N; i++)
	{
		ans *= i;
		ans %= P;
	}
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/17466