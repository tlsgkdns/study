#include <iostream>
#include <stack>
#include <algorithm>
#include <vector>
using namespace std;
using ll = long long;
int n, x, y;
stack<int> s;
struct Point
{
	int x, y;
	int p, q;
	Point(int x1, int y1) : x(x1), y(y1), p(1), q(0) {}

};
bool operator<(const Point& A, const Point& B)
{
	if ((ll)A.q * B.p != (ll)A.p * B.q)
		return (ll)A.q * B.p < (ll)A.p * B.q;
	if (A.y != B.y)
		return A.y < B.y;

	return A.x < B.x;
}

ll ccw(const Point& A, const Point& B, const Point& C)
{
	ll ret = (ll)(A.x * B.y + B.x * C.y + C.x * A.y - B.x * A.y - C.x * B.y - A.x * C.y);
	return ret;
}
vector<Point> p;
int main()
{
	cin.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> x >> y;
		p.push_back(Point(x, y));
	}
	sort(p.begin(), p.end());
	for (int i = 1; i < n; i++)
	{
		p[i].p = p[i].x - p[0].x;
		p[i].q = p[i].y - p[0].y;
	}
	sort(p.begin(), p.end());
	s.push(0);
	s.push(1);
	for (int next = 2; next < n; next++)
	{
		while (s.size() >= 2)
		{
			int first, second;
			second = s.top();
			s.pop();
			first = s.top();

			if (ccw(p[first], p[second], p[next]) > 0)
			{
				s.push(second);
				break;
			}
		}
		s.push(next);
	}
	cout << s.size() << '\n';
}

//https://www.acmicpc.net/problem/1708
/*
Learned Convex Hull
*/