#include <iostream>
#include <cstring>
#include <vector>

using namespace std;
using ll = long long;
vector<ll> S;
ll arr[20001];
bool v[20001];
ll N, A;
ll gcd(ll a, ll b)
{
	if (a < b) swap(a, b);
	while (b > 0)
	{
		ll tmp = a % b;
		a = b;
		b = tmp;
	}
	return a;
}

ll lcm(ll a, ll b)
{
	return a * b / gcd(a, b);
}
ll dfs(ll here)
{
	if (v[here]) return 0;
	v[here] = true;
	return dfs(arr[here]) + 1;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		cin >> A;
		arr[A] = i;
	}
	for (int i = 1; i <= N; i++)
	{
		if (v[i]) continue;
		S.push_back(dfs(i));
	}
	ll ans = 1;
	for (int i = 0; i < (int)S.size(); i++)
		ans = lcm(ans, S[i]);
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/2487