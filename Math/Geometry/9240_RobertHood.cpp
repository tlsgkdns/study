#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
using ll = long long;

struct Point
{
	ll x = 0, y = 0;
	Point(ll _x, ll _y)
	{
		x = _x;
		y = _y;
	}
	Point operator- (Point& p)
	{
		return Point(x - p.x, y - p.y);
	}
	bool operator<(Point& p)
	{
		if (y != p.y) return y < p.y;
		return x < p.x;
	}
};

ll outer(const Point& p1, const Point& p2)
{
	return p1.x * p2.y - p2.x * p1.y;
}

ll ccw(Point& p1, Point& p2, Point& p3)
{
	ll ret = outer(p2 - p1, p3 - p1);
	return (ret > 0 ? 1 : (ret < 0 ? -1 : 0));
}

double getDist(Point& p1, Point& p2)
{
	return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}
Point s(0, 0);
bool cmp(Point a, Point b)
{
	if (outer(a - s, b - s) != 0) return outer(a - s, b - s) > 0;
	return a < b;
}
vector<int> convex(vector<Point>& poly)
{
	sort(poly.begin(), poly.end());
	s = poly[0];
	sort(poly.begin() + 1, poly.end(), cmp);

	vector<int> ret;
	ret.push_back(0); ret.push_back(1);
	for (int now = 2; now < poly.size(); now++)
	{
		while (ret.size() >= 2)
		{
			int l1 = *(ret.end() - 1);
			int l2 = *(ret.end() - 2);
			if (ccw(poly[l2], poly[l1], poly[now]) > 0) break;
			ret.pop_back();
		}
		ret.push_back(now);
	}
	return ret;
}
double solve(vector<Point>& poly)
{
	vector<int> tmp = convex(poly);
	vector<Point> hull;
	for (int h : tmp) hull.push_back(poly[h]);

	double maxDist = 0;
	int p1 = 0, p2 = 1;
	for (int t = 0; t < hull.size() * 2; t++)
	{
		int np1 = (p1 + 1) % hull.size();
		int np2 = (p2 + 1) % hull.size();
		double tmp = outer(hull[np1] - hull[p1], hull[p2] - hull[np2]);
		if (tmp > 0) p1 = np1;
		if (tmp < 0) p2 = np2;
		if (tmp == 0) { p1 = np1; p2 = np2; }
		maxDist = max(maxDist, getDist(hull[p1], hull[p2]));
	}
	return maxDist;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int C, y, x;
	cin >> C;
	vector<Point> arrow;
	for (int c = 0; c < C; c++)
	{
		cin >> y >> x;
		arrow.push_back(Point(y, x));
	}
	cout << fixed;
	cout.precision(10);
	cout << solve(arrow) << '\n';
}

// https://www.acmicpc.net/problem/9240