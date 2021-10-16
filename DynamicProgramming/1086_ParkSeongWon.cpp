#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
using ll = long long;
ll dp[1 << 15][100];
int tMod[751];
int N, K;
vector<string> arr;
vector<int> mod;

ll solve(int sel, int leng, int remain)
{
	ll& ret = dp[sel][remain];
	if (ret != -1) return ret;
	if (sel == (1 << N) - 1)
	{
		if (remain == 0) return ret = 1;
		return ret = 0;
	}
	ret = 0;
	for (int i = 0; i < N; i++)
	{
		if (sel & (1 << i)) continue;
		int tmp = sel | (1 << i);
		ret += solve(tmp, leng + arr[i].length(), (tMod[leng] * mod[i] + remain) % K);
	}
	return ret;
}
ll gcd(ll a, ll b)
{
	while (b != 0)
	{
		ll x = a % b;
		a = b;
		b = x;
	}
	return a;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	memset(dp, -1, sizeof(dp));
	cin >> N;
	arr.resize(N); mod.resize(N);
	for (int i = 0; i < N; i++) cin >> arr[i];
	cin >> K;
	int tm = 1;
	tMod[0] = 1;
	for (int i = 1; i <= 750; i++)
	{
		tm *= 10;
		tm %= K;
		tMod[i] = tm;
	}
	for (int i = 0; i < N; i++)
	{
		int m = 0;
		for (int j = arr[i].size() - 1; j >= 0; j--)
		{
			m += (arr[i][j] - '0') * tMod[arr[i].size() - 1 - j];
			m %= K;
		}
		mod[i] = m;
	}
	ll up = solve(0, 0, 0); ll down = 1;
	for (int i = 1; i <= N; i++) down *= i;
	ll g = gcd(down, up);
	up /= g; down /= g;
	cout << up << "/" << down << '\n';
}

// https://www.acmicpc.net/problem/1086