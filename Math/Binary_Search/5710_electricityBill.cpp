#include <iostream>

using namespace std;
using ll = long long;

int A, B;
int cost[3] = { 2, 3, 5 };
int hour[3] = { 100, 9900, 990000 };
ll calc(int w)
{
	ll ret = 0;
	for (int i = 0; i < 3; i++)
	{
		if (w <= hour[i]) return ret + (w * cost[i]);
		ret += (cost[i] * hour[i]);
		w -= hour[i];
	}
	return ret + (w * 7);
}
int calc2(int money)
{
	int ret = 0;
	for (int i = 0; i < 3; i++)
	{
		if (money <= cost[i] * hour[i]) return ret + (money / cost[i]);
		ret += hour[i];
		money -= cost[i] * hour[i];
	}
	return ret + (money / 7);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	while (true)
	{
		cin >> A >> B;
		if (A == 0 && B == 0) break;
		int total = calc2(A);
		int l = 0, r = (total / 2) + 1;
		while (l + 1 < r)
		{
			int m = (l + r) / 2;
			if (calc(m) + B <= calc(total - m)) l = m;
			else r = m;
		}
		cout << calc(l) << '\n';
	}
}

// https://www.acmicpc.net/problem/5710