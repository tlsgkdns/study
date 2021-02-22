#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

vector<vector<ll>> cache(100001, vector<ll>(4, -1));

ll pls(int n, int rep)
{
	if (n < 0) return 0;
	ll& ret = cache[n][rep];
	if (ret != -1) return ret;
	if (n == 0) return ret = 1;

	ll s1 = (rep == 1) ? 0 : pls(n - 1, 1) % 1000000009;
	ll s2 = (rep == 2) ? 0 : pls(n - 2, 2) % 1000000009;
	ll s3 = (rep == 3) ? 0 : pls(n - 3, 3) % 1000000009;
	ret = s1 + s2 + s3;

	return ret % 1000000009;
}

int main()
{
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];

	for (int i = 0; i < n; i++)
		cout << pls(v[i], 0) << '\n';
}

// https://www.acmicpc.net/problem/15990

/*
mod 1000000009 every statement
*/