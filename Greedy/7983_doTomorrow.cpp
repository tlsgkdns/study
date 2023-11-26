#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using ll = long long;
vector<pair<ll, ll>> H;
ll N, D, T, ans = 0, S = 0;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> D >> T;
		H.push_back({ T, D });
	}
	sort(H.begin(), H.end());
	ans = H[0].first - H[0].second;
	for (int i = 1; i < N; i++)
	{
		int R = H[i].first - H[i].second - H[i - 1].first;
		S += R;
		if (S < 0)
		{
			ans += S;
			S = 0;
		}
	}
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/7983