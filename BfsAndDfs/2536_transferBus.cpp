#include <iostream>
#include <vector>
#include <queue>

using namespace std;


struct Point
{
	int y, x;
	Point(int _y, int _x)
	{
		y = _y;
		x = _x;
	}
};

struct Line
{
	Point src = Point(0, 0), dst = Point(0, 0);
	Line(int _x1, int _y1, int _x2, int _y2)
	{
		src = Point(_y1, _x1);
		dst = Point(_y2, _x2);
	}
	Line retReverse()
	{
		return Line(src.y, src.x, dst.y, dst.x);
	}
};

bool isIntersect(Line l1, Line l2)
{
	if (l1.src.y == l1.dst.y)
	{
		if (l2.src.y == l2.dst.y)
		{
			if (l2.src.y != l1.src.y) return false;
			return ((l2.src.x >= l1.src.x && l2.src.x <= l1.dst.x)
				|| (l1.src.x <= l2.dst.x && l1.src.x >= l2.src.x));
		}
		else
			return (l2.src.x >= l1.src.x && l2.src.x <= l1.dst.x
				&& l2.src.y <= l1.src.y && l2.dst.y >= l1.src.y);
	}
	else
		return isIntersect(l1.retReverse(), l2.retReverse());
}
int M, N, K, b, r1, c1, r2, c2, sx, sy, dx, dy;
vector<Line> bus;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> M >> N;
	cin >> K;
	for (int i = 0; i < K; i++)
	{
		cin >> b >> c1 >> r1 >> c2 >> r2;
		if (c1 == c2 && r1 > r2)
			swap(r1, r2);
		if (r1 == r2 && c1 > c2)
			swap(c1, c2);
		bus.push_back(Line(c1, r1, c2, r2));
	}
	cin >> sx >> sy >> dx >> dy;
	queue<int> q;
	vector<int> v(K + 1, -1);
	vector<int> dest;
	for (int i = 0; i < K; i++)
	{
		if (bus[i].src.x == bus[i].dst.x)
		{
			if (sx == bus[i].src.x && sy >= bus[i].src.y && sy <= bus[i].dst.y)
			{
				v[i] = 1;
				q.push(i);
			}
			if (dx == bus[i].src.x && dy >= bus[i].src.y && dy <= bus[i].dst.y)
				dest.push_back(i);
		}
		else
		{
			if (sy == bus[i].src.y && sx >= bus[i].src.x && sx <= bus[i].dst.x)
			{
				v[i] = 1;
				q.push(i);
			}
			if (dy == bus[i].src.y && dx >= bus[i].src.x && dx <= bus[i].dst.x)
				dest.push_back(i);
		}
	}
	int ans = 1;
	while (!q.empty())
	{
		int n = q.front();
		q.pop();
		bool br = false;
		for (int d : dest)
			if (d == n)
			{
				br = true;
				ans = v[n];
				break;
			}
		if (br) break;
		for (int k = 0; k < K; k++)
		{
			if (!isIntersect(bus[k], bus[n]) || v[k] != -1) continue;
			v[k] = v[n] + 1;
			q.push(k);
		}
	}
	cout << ans << '\n';
}
// https://www.acmicpc.net/problem/2536