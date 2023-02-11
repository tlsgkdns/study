#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
using ll = long long;
ll dp[101], N, D[101], T[101], S, dp2[101];
const long long INF = 10000000000;
ll solve(int here)
{
	if (here == N + 1) return 0;
	ll& ret = dp[here];
	if (ret >= 0) return ret;
	ret = INF;
	int s = D[here], there = here + 1;
	while (there <= N + 1 && s <= S)
	{
		int tmp = solve(there) + T[there];
		if (ret > tmp)
		{
			ret = tmp;
			dp2[here] = there;
		}
		s += D[there++];
	}
	return ret;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	memset(dp, -1, sizeof(dp));
	cin >> S >> N;
	for (int i = 0; i <= N; i++) cin >> D[i];
	for (int i = 1; i <= N; i++) cin >> T[i];
	int ans = solve(0);
	vector<int> R;

	cout << ans << '\n';
	if (ans == 0) cout << 0 << '\n';
	else
	{
		int src = 0;
		while (src != N + 1)
		{
			src = dp2[src];
			R.push_back(src);
		}
		R.pop_back();
		cout << R.size() << '\n';
		for (int r : R) cout << r << " ";
		cout << '\n';
	}
}

// https://www.acmicpc.net/problem/2651