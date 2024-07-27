#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int X, Y, D, T;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cout << fixed; cout.precision(10);
	cin >> X >> Y >> D >> T;
	double dist = sqrt(X * X + Y * Y), ans = 0;
	if (T > D) cout << dist << '\n';
	while (dist > 2 * D)
	{
		dist -= D;
		ans += T;
	}
	ans += min(dist, min(T + abs(D - dist), (double)T * 2));
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/1069