#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

vector<pair<int, pair<int, int>>> arr;
int N, X, Y, T, dp[6667];
double S;
int solve(int idx)
{
	int& ret = dp[idx];
	if (ret >= 0) return ret;
	ret = 0;
	for (int i = idx + 1; i < arr.size(); i++)
	{
		double d = sqrt(pow(arr[idx].second.first - arr[i].second.first, 2)
			+ pow(arr[idx].second.second - arr[i].second.second, 2));
		if (arr[i].first - arr[idx].first < (d / S)) continue;
		ret = max(ret, solve(i) + 1);
	}
	return ret;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	memset(dp, -1, sizeof(dp));
	cin >> N >> S;
	arr.push_back({ 0, {0, 0} });
	for (int i = 0; i < N; i++)
	{
		cin >> X >> Y >> T;
		arr.push_back({ T, {X, Y} });
	}
	sort(arr.begin(), arr.end());
	cout << solve(0) << '\n';
}

// https://www.acmicpc.net/problem/2259