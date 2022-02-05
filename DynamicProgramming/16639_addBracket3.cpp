#include <iostream>
#include <algorithm>
#include <cstring>
#include <limits>

using namespace std;
using ll = long long;
const ll NINF = numeric_limits<ll>::min();
const ll INF = numeric_limits<ll>::max();
ll dp1[21][21], dp2[21][21];
ll solve(int, int);
ll solve2(int, int);
string expr;
int N;
ll solve(int s, int e)
{
	if (s == e) return (ll)(expr[s] - '0');
	ll& ret = dp1[s][e];
	if (dp1[s][e] != NINF) return ret;
	for (int i = s; i <= e - 2; i += 2)
	{
		switch (expr[i + 1])
		{
		case '+':
			ret = max(solve(s, i) + solve(i + 2, e), ret);
			break;
		case '-':
			ret = max(solve(s, i) - solve2(i + 2, e), ret);
			break;
		default:
			ret = max(solve(s, i) * solve(i + 2, e), ret);
			ret = max(solve2(s, i) * solve2(i + 2, e), ret);
			break;
		}
	}
	return ret;
}
ll solve2(int s, int e)
{
	if (s == e) return (ll)(expr[s] - '0');
	ll& ret = dp2[s][e];
	if (dp2[s][e] != INF) return ret;
	for (int i = s; i <= e - 2; i += 2)
	{
		switch (expr[i + 1])
		{
		case '+':
			ret = min(solve2(s, i) + solve2(i + 2, e), ret);
			break;
		case '-':
			ret = min(solve2(s, i) - solve(i + 2, e), ret);
			break;
		default:
			ret = min(solve(s, i) * solve(i + 2, e), ret);
			ret = min(solve(s, i) * solve2(i + 2, e), ret);
			ret = min(solve2(s, i) * solve(i + 2, e), ret);
			ret = min(solve2(s, i) * solve2(i + 2, e), ret);
			break;
		}
	}
	return ret;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	cin >> expr;
	for (int i = 0; i < N + 1; i++)
		for (int j = 0; j < N + 1; j++)
		{
			dp1[i][j] = NINF;
			dp2[i][j] = INF;
		}

	cout << solve(0, N - 1) << '\n';
}

// https://www.acmicpc.net/problem/16639