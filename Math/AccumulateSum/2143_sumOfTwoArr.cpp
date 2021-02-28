#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
int main()
{
	ll t, n, m, ans = 0;
	vector<ll> A, B, pa, pb, subA, subB;
	cin >> t;
	cin >> n; A = vector<ll>(n);
	for (int i = 0; i < n; i++)
		cin >> A[i];
	cin >> m; B = vector<ll>(m);
	for (int i = 0; i < m; i++)
		cin >> B[i];

	for (int i = 0; i < n; i++)
	{
		if (i == 0) pa.push_back(A[i]);
		else pa.push_back(pa[i - 1] + A[i]);
		subA.push_back(pa[i]);
	}
	for (int i = 0; i < m; i++)
	{
		if (i == 0) pb.push_back(B[i]);
		else pb.push_back(pb[i - 1] + B[i]);
		subB.push_back(pb[i]);
	}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < i; j++)
			subA.push_back(pa[i] - pa[j]);
	for (int i = 0; i < m; i++)
		for (int j = 0; j < i; j++)
			subB.push_back(pb[i] - pb[j]);
	sort(subB.begin(), subB.end());
	for (ll s : subA)
	{
		ll ts = t - s;
		auto l = lower_bound(subB.begin(), subB.end(), ts);
		auto r = upper_bound(subB.begin(), subB.end(), ts);
		if (l == subB.end() || ts != *l) continue;
		ans += r - l;
	}
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/2143

/*
Watch out that array's element can be negative
*/