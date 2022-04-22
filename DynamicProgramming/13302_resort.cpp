#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int INF = 1000000000;
int dp[101][41], N, M, D;
int cost[3] = { 10000, 25000, 37000 };
int coup[3] = { 0, 1, 2 }, days[3] = { 1, 3, 5 };
bool dayOff[101];

int solve(int day, int coupon)
{
	if (day > N) return 0;
	int& ret = dp[day][coupon];
	if (ret != -1) return ret;
	ret = INF;
	if (dayOff[day]) ret = min(ret, solve(day + 1, coupon));
	else if (coupon >= 3) ret = min(ret, solve(day + 1, coupon - 3));
	for (int i = 0; i < 3; i++)
		ret = min(ret, solve(day + days[i], coupon + coup[i]) + cost[i]);
	return ret;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	memset(dayOff, false, sizeof(dayOff));
	memset(dp, -1, sizeof(dp));
	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		cin >> D;
		dayOff[D] = true;
	}
	cout << solve(1, 0) << '\n';
}

// https://www.acmicpc.net/problem/13302