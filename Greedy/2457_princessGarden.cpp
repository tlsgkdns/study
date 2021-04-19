#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
const int month[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
bool operator< (pair<int, int> p1, pair<int, int> p2)
{
	if (p1.first < p2.first) return true;
	else if (p1.first > p2.first) return false;
	else return (p1.second < p2.second);
}
int dateToIndex(int m, int d)
{
	int ret = 0;
	for (int i = 0; i < m - 1; i++)
		ret += month[i];
	ret += (d - 1);
	return ret;
}
const int st = dateToIndex(3, 1);
const int ed = dateToIndex(12, 1);
int main()
{
	priority_queue<pair<int, int>> flower;
	int n, p = 0, l = st, r = ed;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int m1, d1, m2, d2, p1, p2;
		cin >> m1 >> d1 >> m2 >> d2;
		p1 = dateToIndex(m1, d1); p2 = dateToIndex(m2, d2);
		p1 = (p1 > st) ? p1 : st; p2 = (p2 < ed) ? p2 : ed;
		flower.push(make_pair(-p1, p2));
	}
	bool flag = true;
	int prev = 0;
	while (!flower.empty() && r != l)
	{
		if (-flower.top().first == l && prev != l)
		{
			l = flower.top().second;
			p++;
		}
		else if (-flower.top().first < l && flower.top().second > l)
		{
			flower.push(make_pair(-l, flower.top().second));
		}
		prev = -flower.top().first;
		flower.pop();
	}
	if (r != l) cout << 0 << '\n';
	else cout << p << '\n';
}

// https://www.acmicpc.net/problem/2457