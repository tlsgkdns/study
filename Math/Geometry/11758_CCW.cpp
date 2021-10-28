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

int main()
{
	point p1, p2, p3;
	cin >> p1.first >> p1.second;
	cin >> p2.first >> p2.second;
	cin >> p3.first >> p3.second;
	cout << ccw(p1, p2, p3) << '\n';
}

// https://www.acmicpc.net/problem/11758