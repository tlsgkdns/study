#include <iostream>
#include <vector>

using namespace std;
using ll = long long;
vector<ll> G;
ll C[2050], N, A, ans = 0;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> A;
		ll b = 0;
		while (A > 0)
		{
			ll n = A % 10;
			b |= (1 << n);
			A /= 10;
		}
		if (C[b] == 0) G.push_back(b);
		++C[b];
	}
	for (int i = 0; i < G.size(); i++)
	{
		ans += (C[G[i]] * (C[G[i]] - 1)) / 2;
		for (int j = i + 1; j < G.size(); j++)
			if ((G[i] & G[j]) > 0)
				ans += C[G[i]] * C[G[j]];
	}
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/2825