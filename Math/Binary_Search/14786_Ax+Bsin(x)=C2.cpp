#include <cmath>
#include <iostream>
using namespace std;
double A, B, C;

bool solve(double a)
{
	return a * A + B * sin(a) < C;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> A >> B >> C;

	double l = 0, r = 1000000001;
	for (int it = 0; it < 100; it++)
	{
		double m = (l + r) / 2;
		if (solve(m)) l = m;
		else r = m;
	}
	cout << fixed;
	cout.precision(11);
	cout << l << '\n';
}

// https://www.acmicpc.net/problem/14786