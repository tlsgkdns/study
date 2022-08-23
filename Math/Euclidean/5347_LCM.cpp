#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
vector<ll> ans;
ll A, B;
int T;
ll gcd(ll a, ll b)
{
	if (a < b) swap(a, b);
	while (b != 0)
	{
		ll tmp = a % b;
		a = b;
		b = tmp;
	}
	return a;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> T;
	while (T--)
	{
		cin >> A >> B;
		ans.push_back((A * B / gcd(A, B)));
	}
	for (ll a : ans) cout << a << '\n';
}

// https://www.acmicpc.net/problem/5347