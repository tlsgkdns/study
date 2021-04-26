#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
using ll = long long;
const int SZ = 2000001;
ll t, a, b;
vector<bool> ans;
vector<ll> prime;
bool isPrime[SZ];
bool canDiv(ll num)
{
	ll idx = 0;
	while (idx < prime.size() && prime[idx] * prime[idx] <= num)
	{

		if (num % prime[idx] == 0) return false;
		idx++;
	}
	return true;
}
int main()
{
	cin >> t;
	memset(isPrime, true, sizeof(isPrime));
	isPrime[0] = isPrime[1] = false;
	for (int i = 2; i * i < SZ; i++)
	{
		if (isPrime[i])
			for (int j = i * i; j < SZ; j += i)
				isPrime[j] = false;
	}
	for (int i = 2; i < SZ; i++) if (isPrime[i]) prime.push_back(i);
	for (int i = 0; i < t; i++)
	{
		cin >> a >> b;
		ll s = a + b;
		if (s < 4)
		{
			ans.push_back(false);
			continue;
		}
		if (s % 2 == 0)
		{
			ans.push_back(true);
			continue;
		}
		s -= 2;
		if (canDiv(s)) ans.push_back(true);
		else ans.push_back(false);
	}
	for (bool a : ans)
		if (a) cout << "YES\n";
		else cout << "NO\n";
}
// https://www.acmicpc.net/problem/15711