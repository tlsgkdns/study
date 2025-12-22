#include <iostream>

using namespace std;
using ll = long long;
ll N, ans = 0;

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(NULL); cin.tie(NULL);
	cin >> N;
	for (ll n = 1; n <= N; n++)
		ans += (n * n * n);
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/20833