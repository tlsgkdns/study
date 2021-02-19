#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
	int m, n, mn, s = 0;

	cin >> m >> n;
	vector<bool> v(n + 1, false);

	for (int i = 2; i < sqrt(n); i++)
	{
		if (v[i]) continue;
		for (int a = i * i; a <= n; a += i)
			v[a] = true;
	}

	v[0] = v[1] = true;
	v[2] = false;

	for (int i = n; i >= m; i--)
		if (!v[i])
		{
			mn = i;
			s += i;
		}

	if (s == 0) cout << -1 << '\n';
	else
	{
		cout << s << '\n';
		cout << mn << '\n';
	}

	return 0;
}

// https://www.acmicpc.net/problem/2581

/*
maybe, I can handle this with no eratosthenes.
*/