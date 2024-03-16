#include <vector>
#include <iostream>
#include <unordered_map>

using ll = long long;
using namespace std;

ll N, A, Z = 0;
unordered_map<ll, ll> um;
vector<ll> neg, pos;
ll ans = 0;
int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> A;
		if (A < 0 && um[A] == 0) neg.push_back(A);
		else if (A > 0 && um[A] == 0) pos.push_back(A);
		++um[A];
	}
	Z = um[0];
	if (Z >= 3) ans += (Z * (Z - 1) * (Z - 2)) / 6;
	ll tmp = 0;
	for (int i = 0; i < neg.size(); i++)
		for (int j = 0; j < pos.size(); j++)
		{
			ll s = -(neg[i] + pos[j]);
			if (s == 0 && Z > 0) tmp += 2 * um[neg[i]] * um[pos[j]] * Z;
			else if ((s == neg[i] || s == pos[j]))
				tmp += (um[-2 * s] * um[s] * (um[s] - 1));
			else
				tmp += um[neg[i]] * um[pos[j]] * um[s];
		}
	ans += (tmp / 2);
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/3151