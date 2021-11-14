#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
using ll = long long;
const double PI = 3.1415926535;
struct Point
{
	ll x, y;

	bool operator<(Point p)
	{
		return make_pair(x, y) < make_pair(p.x, p.y);
	}
	Point()
	{
		x = 0; y = 0;
	}
	Point(ll _x, ll _y)
	{
		x = _x;
		y = _y;
	}
};
int N;
ll L;

vector<Point> build, hull;

double getDist(Point p1, Point p2)
{
	return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}
int ccw(Point a, Point b, Point c)
{
	ll ret = a.x * b.y + b.x * c.y + c.x * a.y;
	ret -= b.x * a.y + c.x * b.y + a.x * c.y;
	if (ret < 0) return -1;
	return (ret > 0);
}
ll dot(Point a, Point b)
{
	return a.x * b.x + a.y * b.y;
}
bool cmp(Point& a, Point& b)
{
	int cw = ccw(build[0], a, b);
	if (cw != 0) return cw > 0;
	return getDist(build[0], a) < getDist(build[0], b);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> L;
	build.resize(N);
	for (int i = 0; i < N; i++) cin >> build[i].x >> build[i].y;
	swap(build[0], *max_element(build.begin(), build.end()));
	sort(build.begin() + 1, build.end(), cmp);
	for (Point& p : build)
	{
		while (hull.size() >= 2 && ccw(hull[hull.size() - 2], hull.back(), p) <= 0) hull.pop_back();
		hull.push_back(p);
	}
	double ans = 0;
	int n = hull.size();
	for (int i = 0; i < n; i++)
	{
		Point prev = hull[(i + n - 1) % n], next = hull[(i + 1) % n];
		double d1 = getDist(hull[i], next), d2 = getDist(hull[i], prev);
		ans += d1;
		ll inn = dot(Point(prev.x - hull[i].x, prev.y - hull[i].y), Point(next.x - hull[i].x, next.y - hull[i].y));
		double theta = acos((double)inn / (d1 * d2));
		theta = PI - theta;
		ans += L * theta;
	}
	cout << fixed;
	cout.precision(0);
	cout << ans << '\n';
}
// https://www.acmicpc.net/problem/7420