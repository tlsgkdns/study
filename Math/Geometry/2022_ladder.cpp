#include <iostream>
#include <cmath>

using namespace std;

double l = 0, r = 3000000001, x, y, c;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> x >> y >> c;
	while (l + 0.001 < r)
	{
		double m = (l + r) / 2;
		double h1 = sqrt(pow(x, 2) - pow(m, 2));
		double h2 = sqrt(pow(y, 2) - pow(m, 2));
		if ((h1 * h2) / (h1 + h2) >= c) l = m;
		else r = m;
	}
	cout << fixed;  cout.precision(4);
	cout << r << '\n';
}

// https://www.acmicpc.net/problem/2022