#include <iostream>
#include <vector>
#include <bitset>
#include <algorithm>
#define INF 100000000

using namespace std;

vector<int> dp;
vector<vector<int>> power;
int n, p, a;
int plant(bitset<16> b)
{
	int& ret = dp[b.to_ulong()];
	if (ret < INF) return ret;
	if (b.count() >= p) return ret = 0;
	for (int i = 0; i < n; i++)
	{
		if (b[i] != 1) continue;
		for (int j = 0; j < n; j++)
		{
			if (b[j] != 0 || i == j) continue;
			b.set(j);
			ret = min(plant(b) + power[i][j], ret);
			b.reset(j);
		}
	}
	return ret;
}
int main()
{
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	cin >> n;
	dp.resize(1 << n, INF);
	power = vector<vector<int>>(n, vector<int>(n));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> power[i][j];
	bitset<16> b;
	string state;
	cin >> state;
	b.reset();
	for (int i = 0; i < n; i++)
		if (state[i] == 'N') b.reset(i);
		else b.set(i);
	cin >> p;
	a = plant(b);
	if (a >= INF) cout << -1 << '\n';
	else cout << a << '\n';
}

// https://www.acmicpc.net/problem/1102

/*
training dynamic with bitmask
*/