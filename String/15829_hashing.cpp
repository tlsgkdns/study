#include <iostream>

using namespace std;
using ll = long long;
const ll MOD = 1234567891;
int L;
ll r = 1, ans = 0;
string A;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> L;
	cin >> A;
	for (int i = 0; i < L; i++)
	{
		ans += (A[i] - 'a' + 1) * r;
		ans %= MOD;
		r *= 31;
		r %= MOD;
	}
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/15829