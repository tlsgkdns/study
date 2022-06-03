#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
using ll = long long;
int N, l, r;
ll sub = 100000000000;
vector<ll> liq, ans(3);
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N; liq.resize(N);
	for (int i = 0; i < N; i++) cin >> liq[i];
	sort(liq.begin(), liq.end());
	for (int idx = 0; idx < N; idx++)
	{
		l = (idx != 0) ? 0 : 1, r = (idx != N - 1) ? N - 1 : N - 2;
		while (l < r)
		{
			if (sub > abs(liq[l] + liq[r] + liq[idx]))
			{
				ans[0] = liq[l];
				ans[1] = liq[r];
				ans[2] = liq[idx];
				sub = abs(liq[l] + liq[r] + liq[idx]);
			}
			if (liq[l] + liq[r] + liq[idx] > 0)
			{
				r--;
				if (idx == r) r--;
			}
			else
			{
				l++;
				if (idx == l) l++;
			}
		}
	}
	sort(ans.begin(), ans.end());
	cout << ans[0] << " " << ans[1] << " " << ans[2] << '\n';
}

// https://www.acmicpc.net/problem/2473