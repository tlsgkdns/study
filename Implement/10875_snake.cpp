#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
using ll = long long;
using pii = pair<ll, ll>;

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, -1, 0, 1 };

const ll INF = 1000000000000;
struct Line
{
	pii src, dst;
	bool isHor = false, increase = false;
	ll leng = 0;
};
ll L, N, T, dir = 0, ans = 0;
char cmd;
ll ccw(pii a, pii b, pii c)
{
	ll op = a.first * b.second + b.first * c.second + c.first * a.second;
	op -= (a.second * b.first + b.second * c.first + c.second * a.first);
	if (op > 0) return 1;
	else if (op == 0) return 0;
	else return -1;
}

bool isIntersect(Line l1, Line l2)
{
	pii a = l1.src; pii b = l1.dst;
	pii c = l2.src; pii d = l2.dst;
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
int getClockDir(int dir)
{
	return (dir + 1) % 4;
}
int getAntiClockDir(int dir)
{
	return (dir + 3) % 4;
}
ll isCollide(Line l1, Line l2)
{
	if (!isIntersect(l1, l2)) return -1;
	if (l1.isHor)
	{
		if (l2.isHor)
		{
			if (l2.increase)
				return abs(l1.src.first - l2.src.first);
			else
				return abs(l1.src.first - l2.dst.first);
		}
		else
			return abs(l2.src.first - l1.src.first);
	}
	else
	{
		if (l2.isHor)
			return abs(l2.src.second - l1.src.second);
		else
		{
			if (l2.increase)
				return abs(l1.src.second - l2.src.second);
			else
				return abs(l1.src.second - l2.dst.second);
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	vector<Line> body;
	cin >> L; cin >> N;
	L++;
	pii head, next, p1, p2;
	Line b1, b2, b3, b4;
	b1.src.first = L; b1.dst.first = -L;
	b1.src.second = L; b1.dst.second = L;
	b1.isHor = true;
	b2.src.first = L; b2.dst.first = -L;
	b2.src.second = -L; b2.dst.second = -L;
	b2.isHor = true;
	b3.src.second = L; b3.dst.second = -L;
	b3.src.first = L; b3.dst.first = L;
	b3.isHor = false;
	b4.src.second = L; b4.dst.second = -L;
	b4.src.first = -L; b4.dst.first = -L;
	b4.isHor = false;
	body.push_back(b1); body.push_back(b2);
	body.push_back(b3); body.push_back(b4);
	Line dm;
	dm.src = { L + 1, L + 1 }; dm.dst = { L + 1, -L - 1 };
	dm.isHor = false; dm.increase = false;
	body.push_back(dm);
	head.first = 0; head.second = 0;
	dir = 0;
	for (int i = 0; i < N; i++)
	{
		cin >> T >> cmd;
		Line line;
		line.src = head;
		next.first = head.first + dx[dir] * T;
		next.second = head.second + dy[dir] * T;
		line.src = head; line.dst = next;
		line.isHor = (dir % 2 == 0);
		line.increase = ((dir == 0) || (dir == 3));
		line.leng = T;
		body.push_back(line);
		if (cmd == 'L') dir = getAntiClockDir(dir);
		else dir = getClockDir(dir);
		head = next;
	}
	Line ad; ad.src = head;
	ad.dst = head;
	switch (dir)
	{
	case 0:
		ad.dst.first = L;
		ad.isHor = true;
		ad.increase = true;
		ad.leng = L - head.first;
		break;
	case 1:
		ad.dst.second = -L;
		ad.isHor = false;
		ad.increase = false;
		ad.leng = abs(-L - head.second);
		break;
	case 2:
		ad.dst.first = -L;
		ad.isHor = true;
		ad.increase = false;
		ad.leng = abs(-L - head.second);
		break;
	default:
		ad.dst.second = L;
		ad.isHor = false;
		ad.increase = true;
		ad.leng = abs(L - head.second);
	}
	body.push_back(ad);
	for (int i = 5; i < body.size(); i++)
	{
		ll brp = INF;
		for (int j = 0; j < i - 1; j++)
		{
			ll cld = isCollide(body[i], body[j]);
			if (cld != -1)
				brp = min(brp, cld);
		}
		if (brp != INF)
		{
			ans += brp;
			break;
		}
		ans += body[i].leng;
	}
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/10875