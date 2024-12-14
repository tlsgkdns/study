#include <iostream>
#include <unordered_map>
using namespace std;
using ll = long long;
ll C, D, N, A[50001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> C;
	while (C--)
	{
		unordered_map<ll, ll> cnt;
		cnt[0]++;
		cin >> D >> N;
		for (int i = 1; i <= N; i++)
		{
			cin >> A[i];
			A[i] = (A[i] + A[i - 1]) % D;
			cnt[A[i]]++;
		}
		ll ans = 0;
		for (const auto& p : cnt)
			ans += (p.second * (p.second - 1)) / 2;
		cout << ans << '\n';
	}
}

// https://www.acmicpc.net/problem/3673