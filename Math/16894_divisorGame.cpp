#include <iostream>
using namespace std;
using ll = long long;
ll N;

int solve(ll num)
{
	int ret = 0;
	for (ll n = 2; n * n <= num && num > 1; n++)
		while (num % n == 0)
		{
			num /= n;
			++ret;
		}
	ret += (num > 1);
	return ret;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	if (solve(N) != 2) cout << "koosaga\n";
	else cout << "cubelover\n";
}

// https://www.acmicpc.net/problem/16894