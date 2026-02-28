#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
using ll = long long;
vector<ll> num[2];
ll N, K, A, ans = 0;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> K;
	for (int i = 0; i < N; i++)
	{
		cin >> A;
		num[A % 2].push_back(-A);
	}
	for (int i = 0; i < 2; i++)
	{
		if (num[i].size() >= K)
		{
			ll s = 0;
			sort(num[i].begin(), num[i].end());
			for (int j = 0; j < K; j++)
				s -= num[i][j];
			ans = max(ans, s);
		}
	}
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/35349