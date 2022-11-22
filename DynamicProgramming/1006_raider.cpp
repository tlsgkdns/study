#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

const int INF = 1000000001;
int dp[20001][2][2][2], N, W, T;
int area[20001];
vector<int> ans;
int solve(int idx, bool outsideLastFilled, bool insideLastFilled, bool cantGoNext)
{
	if (idx >= N) return 0;
	int& ret = dp[idx][outsideLastFilled][insideLastFilled][cantGoNext];
	if (ret >= 0) return ret;
	ret = INF;
	if (idx == 0 && N - 4 > 0 && area[N - 2] + area[idx] <= W)
		ret = min(ret, solve(idx + 1, true, insideLastFilled, cantGoNext) + 1);
	if (idx == 1 && N - 4 > 0 && area[N - 1] + area[idx] <= W)
	{
		if (cantGoNext)
			ret = min(ret, solve(idx + 2, outsideLastFilled, true, false) + 1);
		else
			ret = min(ret, solve(idx + 1, outsideLastFilled, true, cantGoNext) + 1);
	}
	bool isNextEmpty = (!cantGoNext && !((idx == N - 2 && insideLastFilled) || (idx == N - 3 && outsideLastFilled)));
	bool isSideEmpty = !((idx == N - 3 && insideLastFilled) || (idx == N - 4 && outsideLastFilled));
	if (idx % 2 == 0 && area[idx] + area[idx + 1] <= W && isNextEmpty)
	{
		if (isSideEmpty)
			ret = min(ret, solve(idx + 2, outsideLastFilled, insideLastFilled, false) + 1);
		else if ((idx == N - 4 && insideLastFilled))
			ret = min(ret, solve(idx + 4, outsideLastFilled, insideLastFilled, false) + 1);
		else
			ret = min(ret, solve(idx + 3, outsideLastFilled, insideLastFilled, false) + 1);
	}
	if (idx <= N - 3 && area[idx] + area[idx + 2] <= W && isSideEmpty)
	{
		if (!isNextEmpty)
		{
			if (idx == N - 5 && outsideLastFilled)
			{
				if (insideLastFilled)
					ret = min(ret, solve(idx + 5, outsideLastFilled, insideLastFilled, false) + 1);
				else
					ret = min(ret, solve(idx + 4, outsideLastFilled, insideLastFilled, false) + 1);
			}
			else if (idx == N - 4 && insideLastFilled)
				ret = min(ret, solve(idx + 4, outsideLastFilled, insideLastFilled, false) + 1);
			else
				ret = min(ret, solve(idx + 3, outsideLastFilled, insideLastFilled, false) + 1);
		}
		else
			ret = min(ret, solve(idx + 1, outsideLastFilled, insideLastFilled, true) + 1);
	}
	if (!isNextEmpty)
	{
		if (!isSideEmpty)
		{
			if (idx == N - 4 && insideLastFilled)
				ret = min(ret, solve(idx + 4, outsideLastFilled, insideLastFilled, false) + 1);
			else
				ret = min(ret, solve(idx + 3, outsideLastFilled, insideLastFilled, false) + 1);
		}
		else
			ret = min(ret, solve(idx + 2, outsideLastFilled, insideLastFilled, false) + 1);
	}
	else
		ret = min(ret, solve(idx + 1, outsideLastFilled, insideLastFilled, false) + 1);
	return ret;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> T;
	while (T--)
	{
		memset(dp, -1, sizeof(dp));
		cin >> N >> W; N *= 2;
		for (int i = 0; i < N; i += 2) cin >> area[i];
		for (int i = 1; i < N; i += 2) cin >> area[i];
		ans.push_back(solve(0, false, false, false));
	}
	for (int i = 0; i < ans.size(); i++) cout << ans[i] << '\n';
}

// https://www.acmicpc.net/problem/1006