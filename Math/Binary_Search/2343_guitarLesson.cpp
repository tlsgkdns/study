#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 1000000000;

vector<int> lesson;
int n, m;

bool solve(int num)
{
	int ret = 0, s = 0;
	for (int i = 0; i < n; i++)
	{
		if (s + lesson[i] > num)
		{
			if (s == 0) return false;
			ret++;
			s = 0;
		}
		s += lesson[i];
	}
	ret += (s <= num);
	return ret <= m;
}
int main()
{
	cin >> n >> m;
	lesson.resize(n);
	int r = INF, l = -1;
	for (int i = 0; i < n; i++)
	{
		cin >> lesson[i];
		l = max(lesson[i], l);
	}
	l--;
	while (l + 1 < r)
	{
		int mid = (l + r) / 2;
		if (solve(mid)) r = mid;
		else l = mid;
	}
	cout << r << '\n';
}
// https://www.acmicpc.net/problem/2343