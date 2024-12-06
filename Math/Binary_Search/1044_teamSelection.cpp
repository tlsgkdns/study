#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <unordered_map>
using namespace std;
using ll = long long;
int N;
ll T[2][36];
vector<ll> t1, t2;
vector<pair<ll, pair<ll, int>>> P;
vector<ll> ps[19];
unordered_map<ll, ll> um[19];
void dfs(int idx1, int idx2, ll s1, ll s2, int e, ll b, int cnt)
{
	if (idx2 == e)
	{
		if (idx1 == 1)
		{
			if (um[cnt].find(s1 - s2) == um[cnt].end())
			{
				ps[cnt].push_back(s1 - s2);
				um[cnt][s1 - s2] = b;
			}
			else
				um[cnt][s1 - s2] = min(um[cnt][s1 - s2], b);
		}
		else
			P.push_back({ s1 - s2, {b, cnt} });
		return;
	}
	dfs(idx1, idx2 + 1, s1 + T[0][idx2], s2, e, b, cnt + 1);
	dfs(idx1, idx2 + 1, s1, s2 + T[1][idx2], e, b | ((ll)1 << (N - idx2 - 1)), cnt);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++) cin >> T[0][i];
	for (int i = 0; i < N; i++) cin >> T[1][i];
	dfs(0, 0, 0, 0, (N / 2), 0, 0);
	dfs(1, (N / 2), 0, 0, N, 0, 0);
	for (int i = 0; i < 19; i++)
		sort(ps[i].begin(), ps[i].end());
	ll sub = 1e18, b = 0;
	for (int i = 0; i < P.size(); i++)
	{
		int target = (N / 2) - P[i].second.second;
		if (ps[target].empty()) continue;
		int l = 0, r = ps[target].size() - 1;
		while (l + 1 < r)
		{
			int m = (l + r) / 2;
			if (ps[target][m] < -P[i].first) l = m;
			else r = m;
		}
		if (sub > abs(ps[target][l] + P[i].first))
		{
			sub = abs(ps[target][l] + P[i].first);
			b = P[i].second.first + um[target][ps[target][l]];
		}
		else if (sub == abs(ps[target][l] + P[i].first))
		{
			b = min(P[i].second.first + um[target][ps[target][l]], b);
		}
		if (sub > abs(ps[target][r] + P[i].first))
		{
			sub = abs(ps[target][r] + P[i].first);
			b = P[i].second.first + um[target][ps[target][r]];
		}
		else if (sub == abs(ps[target][r] + P[i].first))
		{
			b = min(P[i].second.first + um[target][ps[target][r]], b);
		}
	}
	for (ll n = pow(2, N - 1); n > 0; n /= 2)
	{
		int input = 1;
		if (b & n)
		{
			input = 2;
		}
		cout << input << " ";
	}
	cout << '\n';
}

// https://www.acmicpc.net/problem/1044