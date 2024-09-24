#include <iostream>
#include <cmath>
using namespace std;
using ll = long long;

int L, U;
ll C[12];
ll solve(int num)
{
	if (num <= 0) return 0;
	if (num < 10)
	{
		int s = 0;
		for (int i = 1; i <= num; i++)
			s += i;
		return s;
	}
	ll d = 10, ret = 0, tmp; int idx = 0;
	while (num >= d)
	{
		d *= 10;
		++idx;
	}
	d /= 10;
	tmp = d;
	while (num >= tmp)
	{
		ret += C[idx] + (((tmp / d) - 1) * d);
		tmp += d;
	}
	tmp -= d;
	ret += (tmp / d);
	return ret + (tmp / d) * (num % d) + solve(num % d);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> L >> U;
	C[1] = 45;
	for (int i = 2; i < 12; i++)
		C[i] = C[i - 1] * 10 + C[1] * pow(10, i - 1);
	cout << solve(U) - solve(L - 1) << '\n';
}

// https://www.acmicpc.net/problem/1081