#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const ll INF = 1e12;
pii arr[10001];
ll dp[10001];
int N;

ll solve(int idx)
{
	if (idx == N) return 0;
	ll& ret = dp[idx];
	if (ret >= 0) return ret;
	ret = INF;
	int s = 0;
	for (int i = idx; i < N; i++)
	{
		s = max(s, max(abs(arr[i].first - arr[idx].first), abs(arr[i].second) * 2));
		ret = min(ret, solve(i + 1) + s);
	}
	return ret;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	memset(dp, -1, sizeof(dp));
	cin >> N;
	for (int i = 0; i < N; i++) cin >> arr[i].first >> arr[i].second;
	sort(arr, arr + N);
	cout << solve(0) << '\n';
}

// https://www.acmicpc.net/problem/2300