#include <iostream>

using namespace std;
using ll = long long;


ll l = 1, r = 2, G;
bool f = false;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> G;
	while (l < r)
	{
		ll sub = (r * r - l * l);
		if (sub == G)
		{
			f = true;
			cout << r++ << '\n';
		}
		else if (sub > G)
		{
			l++;
		}
		else
		{
			r++;
		}
	}
	if (!f) cout << -1 << '\n';
}

// https://www.acmicpc.net/problem/1484