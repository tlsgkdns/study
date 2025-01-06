#include <iostream>
#include <string>
#include <cstring>
#include <cmath>

using namespace std;
using ll = unsigned long long;
const ll INF = 1e19;
ll dp[20][1025][11][2][2], N;
bool v[20][1025][11][2][2];
int K, s[20];
string str = "";
const int MAX = 19;
ll solve(int idx, int sel, int cnt, bool b, bool z)
{
	if (idx == 0)
	{
		if (cnt == K) return 0;
		return INF;
	}
	ll& ret = dp[idx][sel][cnt][b][z];
	if (v[idx][sel][cnt][b][z]) return ret;
	v[idx][sel][cnt][b][z] = true;
	ret = INF;
	for (ll i = ((b) ? 0 : s[MAX - idx]); i <= 9; i++)
	{
		if (!(sel & (1 << i)))
		{
			if (z && i == 0)
				ret = min(ret, i * (ll)pow(10, idx - 1) + solve(idx - 1, sel, cnt, b, z));
			else if (cnt < K)
				ret = min(ret, i * (ll)pow(10, idx - 1) + solve(idx - 1, (sel | (1 << i)), cnt + 1, b || (i > s[MAX - idx]), false));
		}
		else
		{
			ret = min(ret, i * (ll)pow(10, idx - 1) + solve(idx - 1, sel, cnt, b || (i > s[MAX - idx]), z));
		}
	}
	return ret;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> K;
	memset(dp, -1, sizeof(dp));
	str = to_string(N);
	for (int i = 0; i < str.size(); i++) s[MAX - str.size() + i] = (str[i] - '0');
	cout << solve(MAX, 0, 0, false, true) << '\n';
}

// https://www.acmicpc.net/problem/1040