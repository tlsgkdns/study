#include <iostream>
#include <cmath>

using namespace std;
using ll = long long;
using p = pair<ll, ll>;
ll N, r, c, t = 0, ans = -1;
void rec(p leftUp, p rightDown)
{
	p target = make_pair(r, c);
	if (ans != -1) return;
	if (leftUp <= target && target <= rightDown)
	{
		if (leftUp == rightDown)
		{
			if (leftUp == make_pair(r, c))
				ans = t;
			t++;
			return;
		}
		ll halfR = (leftUp.first + rightDown.first) / 2;
		ll halfC = (leftUp.second + rightDown.second) / 2;
		rec(leftUp, make_pair(halfR, halfC));
		rec(make_pair(leftUp.first, halfC + 1), make_pair(halfR, rightDown.second));
		rec(make_pair(halfR + 1, leftUp.second), make_pair(rightDown.first, halfC));
		rec(make_pair(halfR + 1, halfC + 1), rightDown);
	}
	else
	{
		ll skip = ((rightDown.first - leftUp.first) + 1) * ((rightDown.second - leftUp.second) + 1);
		t += skip;
	}
}
/*
0 2

*/
int main()
{
	cin >> N >> r >> c;
	ll end = pow(2, N);
	rec(make_pair(0, 0), make_pair(end - 1, end - 1));
	cout << ans << '\n';
}
// https://www.acmicpc.net/problem/1074