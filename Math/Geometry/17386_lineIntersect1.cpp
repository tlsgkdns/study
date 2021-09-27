#include <iostream>

using namespace std;
using ll = long long;
using point = pair<ll, ll>;
using line = pair<point, point>;
int ccw(point a, point b, point c)
{
	ll op = a.first * b.second + b.first * c.second + c.first * a.second;
	op -= (a.second * b.first + b.second * c.first + c.second * a.first);
	if (op > 0) return 1;
	else if (op == 0) return 0;
	else return -1;
}

bool isIntersect(line x, line y)
{
	point a = x.first;
	point b = x.second;
	point c = y.first;
	point d = y.second;

	int ab = ccw(a, b, c) * ccw(a, b, d);
	int cd = ccw(c, d, a) * ccw(c, d, b);
	if (ab == 0 && cd == 0)
	{
		if (a > b) swap(a, b);
		if (c > d) swap(c, d);
		return c <= b && a <= d;
	}
	return ab <= 0 && cd <= 0;
}
int main()
{
	line l1, l2;
	cin >> l1.first.first >> l1.first.second >> l1.second.first >> l1.second.second;
	cin >> l2.first.first >> l2.first.second >> l2.second.first >> l2.second.second;
	if (isIntersect(l1, l2)) cout << 1 << '\n';
	else cout << 0 << '\n';
}

// https://www.acmicpc.net/problem/17386