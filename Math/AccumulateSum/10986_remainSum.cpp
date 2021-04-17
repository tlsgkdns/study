#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
vector<ll> psum, arr, group;
int main()
{
	ll n, m, ans = 0;
	cin >> n >> m;
	arr.resize(n); psum.resize(n);
	group.resize(m, 0);
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
		if (i == 0) psum[i] = arr[i];
		else psum[i] = psum[i - 1] + arr[i];
		int rem = psum[i] % m;
		group[rem]++;
	}
	ans += group[0];
	for (int i = 0; i < m; i++)
		ans += (group[i] * (group[i] - 1)) / 2;
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/10986