#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
vector<pii> P;
ll dp[300001];
int N, h, c, S, H[300001], C[300001];

bool cmp(const pii& p1, const pii& p2)
{
	return p1.first < p2.first;
}
ll solve(int idx)
{
	if (idx >= N) return 0;
	ll& ret = dp[idx];
	if (ret >= 0) return ret;
	int nxt = lower_bound(H, H + N, H[idx] + S) - H;
	ret = max(solve(idx + 1), solve(nxt) + C[idx]);
	return ret;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	memset(dp, -1, sizeof(dp));
	cin >> N >> S;
	for (int i = 0; i < N; i++)
	{
		cin >> h >> c;
		P.push_back({ h, c });
	}
	sort(P.begin(), P.end(), cmp);
	for (int i = 0; i < N; i++)
	{
		H[i] = P[i].first;
		C[i] = P[i].second;
	}
	int idx = 0;
	while (idx < N && P[idx].first < S) ++idx;
	cout << solve(idx) << '\n';
}

// https://www.acmicpc.net/problem/2515