#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
using ll = long long;
vector<ll> ans;
const int MAX = 1000001;
int stock[MAX], m[MAX];
int T, N;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> T;
	for (int t = 0; t < T; t++)
	{
		cin >> N;
		memset(m, 0, sizeof(m));
		for (int i = 0; i < N; i++)
			cin >> stock[i];
		m[N - 1] = stock[N - 1];
		for (int i = N - 2; i >= 0; i--)
			m[i] = max(m[i + 1], stock[i]);
		ll a = 0, cnt = 0, s = 0;
		for (int i = 0; i < N; i++)
		{
			if (m[i] > stock[i])
			{
				cnt++;
				s += stock[i];
			}
			else
			{
				a += (stock[i] * cnt) - s;
				cnt = 0;
				s = 0;
			}
		}
		ans.push_back(a);
	}
	for (ll a : ans) cout << a << '\n';
}

// https://www.acmicpc.net/problem/11501