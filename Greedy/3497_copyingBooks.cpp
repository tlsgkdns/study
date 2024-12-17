#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;
int N, M, K;
ll P[501];
bool solve(ll l)
{
	ll s = 0;
	int cnt = 1;
	for (int i = M - 1; i >= 0; i--)
	{
		s += P[i];
		if (s > l)
		{
			s = P[i];
			++cnt;
		}
	}
	return cnt <= K;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	while (N--)
	{
		ll S = 0;
		cin >> M >> K;
		ll l = 0, r = 1e18;
		for (int i = 0; i < M; i++)
		{
			cin >> P[i];
			l = max(l, P[i]);
			S += P[i];
		}
		l--;
		while (l + 1 < r)
		{
			ll m = (l + r) / 2;
			if (solve(m)) r = m;
			else l = m;
		}
		ll s = 0, cnt = 0;
		int rem = K;
		vector<int> c;
		for (int i = M - 1; i >= 0; i--)
		{
			++cnt;
			s += P[i];
			if (s > r)
			{
				c.push_back(cnt - 1);
				s = P[i];
				cnt = 1;
				--rem;
			}
			if (i + 1 == rem)
			{
				c.push_back(cnt);
				while (i-- > 0) c.push_back(1);
				cnt = -1;
				break;
			}

		}
		if (cnt > 0) c.push_back(cnt);
		reverse(c.begin(), c.end());
		int idx = 0;
		for (int i = 0; i < c.size(); i++)
		{
			for (int j = 0; j < c[i]; j++, idx++)
				cout << P[idx] << " ";
			if (i < c.size() - 1)
				cout << "/ ";
		}
		cout << '\n';
	}
}

// https://www.acmicpc.net/problem/3487