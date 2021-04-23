#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
using ll = long long;

int n;
string s;

ll calc(ll num1, char op, ll num2)
{
	ll ret = 0;
	switch (op)
	{
	case '+':
		ret = num1 + num2;
		break;
	case '-':
		ret = num1 - num2;
		break;
	case '*':
		ret = num1 * num2;
		break;
	}

	return ret;
}
ll calc(string st, vector<bool> calculated)
{
	ll res = (ll)st[0] - '0';

	for (int i = 2; i < n;)
	{
		char op = st[i - 1];
		int num;
		if (calculated[i])
		{
			if (i == 2 && calculated[0]) continue;
			num = calc((ll)st[i] - '0', st[i + 1], (ll)st[i + 2] - '0');
			i += 4;
		}
		else
		{
			num = st[i] - '0';
			i += 2;
		}
		res = calc(res, op, num);
	}

	return res;
}

ll bracket(int pos, string st, vector<bool> c)
{
	if (pos >= n - 1) return calc(st, c);

	ll ret = bracket(pos + 2, st, c);
	c[pos] = true;
	c[pos + 1] = true;
	ret = max(ret, bracket(pos + 4, st, c));

	return ret;
}
int main()
{
	cin >> n;
	cin >> s;
	vector<bool> c(n, false);

	ll ans = bracket(0, s, c);

	cout << ans << endl;

	return 0;
}

//  https://www.acmicpc.net/problem/16637