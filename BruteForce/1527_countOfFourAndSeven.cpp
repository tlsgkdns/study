#include <iostream>

using namespace std;

using ll = long long;
int A, B, ans = 0;

void solve(ll n, ll d)
{
	if (n > B) return;
	if (A <= n) ++ans;
	solve(n + d * 4, d * 10);
	solve(n + d * 7, d * 10);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> A >> B;
	solve(0, 1);
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/1527