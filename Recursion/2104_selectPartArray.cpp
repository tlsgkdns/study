#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
ll INF = numeric_limits<ll>::max();
vector<ll> arr;
ll solve(int l, int r)
{
	if (l == r)
	{
		return arr[l] * arr[l];
	}
	int mid = (l + r) / 2;
	ll ret = max(solve(l, mid), solve(mid + 1, r));
	int lo = mid, hi = mid;
	ll m = arr[mid], s = arr[mid];
	while (lo > l || hi < r)
	{
		if (hi < r && (lo == l || arr[lo - 1] < arr[hi + 1]))
		{
			hi++;
			s += arr[hi];
			m = min(m, arr[hi]);
		}
		else
		{
			lo--;
			s += arr[lo];
			m = min(m, arr[lo]);
		}
		ret = max(ret, s * m);
	}

	return ret;
}
int main()
{
	int n;
	cin >> n;
	arr.resize(n);
	for (int i = 0; i < n; i++) cin >> arr[i];
	cout << solve(0, n - 1) << '\n';
}

// https://www.acmicpc.net/problem/2104