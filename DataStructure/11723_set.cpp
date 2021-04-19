#include <iostream>
#include <vector>
#include <bitset>
using namespace std;
bitset<20> b, cl, a;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	b.reset();
	cl.reset();
	a.set();
	string f;
	int m, s;
	cin >> m;
	vector<bool> r;
	for (int i = 0; i < m; i++)
	{
		cin >> f;
		if (f == "all")
			b = a;
		else if (f == "empty")
			b = cl;
		else
		{
			cin >> s;
			if (f == "add")
				b.set(s - 1);
			if (f == "check")
				r.push_back(b.test(s - 1));
			if (f == "remove")
				b.reset(s - 1);
			if (f == "toggle")
				b.flip(s - 1);
		}

	}
	for (bool a : r)
		cout << a << '\n';
}

// https://www.acmicpc.net/problem/11723