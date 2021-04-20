#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
using ll = long long;
using p = pair<ll, ll>;
vector<p> point;

ll area = 0;

ll ccw(p p1, p p2, p p3)
{
	ll tmp = (p1.first * p2.second + p2.first * p3.second + p3.first * p1.second)
		- (p1.second * p2.first + p2.second * p3.first + p3.second * p1.first);
	return tmp;
}
int main()
{
	int n;
	cin >> n; point.resize(n);
	for (int i = 0; i < n; i++)
		cin >> point[i].first >> point[i].second;
	for (int i = 0; i < n - 1; i++)
		area += ccw(point[0], point[i], point[i + 1]);
	cout << fixed;
	cout.precision(1);
	cout << abs(area / 2.0) << '\n';
}

// https://www.acmicpc.net/problem/2166