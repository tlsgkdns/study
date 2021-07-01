#include <iostream>

using namespace std;
int ans = 0;
void cal(int num, int inc)
{
	while (num != 0)
	{
		if (num % 10 == 1) ans += inc;
		num /= 10;
	}
}
void solve(int l, int r, int d)
{
	if (l == 0 || r == 0 || l > r) return;
	while (l != r && l % 10 != 0)
	{
		cal(l, d);
		l++;
	}
	while (r != l && r % 10 != 9)
	{
		cal(r, d);
		r--;
	}
	if (l == r)
	{
		cal(l, d);
		return;
	}
	int inc = (r / 10) - (l / 10) + 1;
	ans += inc * d;
	solve(l / 10, r / 10, d * 10);
}
int main()
{
	int n;
	cin >> n;
	int l = 1, r = n, digit = 1;
	solve(l, r, 1);
	cout << ans << '\n';
}

// https://leetcode.com/problems/number-of-digit-one/