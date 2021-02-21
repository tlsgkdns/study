#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <numeric>

using namespace std;
int mn = numeric_limits<int>::max(), mx = numeric_limits<int>::min();

void calc(int o[4], list<int> arr, int num)
{
	if (arr.empty())
	{
		mn = min(mn, num);
		mx = max(mx, num);
		return;
	}
	int target = arr.front();
	arr.pop_front();
	for (int op = 0; op < 4; op++)
	{
		if (o[op] == 0) continue;
		o[op]--;
		switch (op)
		{
		case 0:
			calc(o, arr, num + target);
			break;
		case 1:
			calc(o, arr, num - target);
			break;
		case 2:
			calc(o, arr, num * target);
			break;
		case 3:
			calc(o, arr, num / target);
			break;
		}
		o[op]++;
	}

}

int main()
{
	int n;
	int ops[4];
	list<int> arr;

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int tmp;
		cin >> tmp;
		arr.push_back(tmp);
	}

	for (int i = 0; i < 4; i++)
		cin >> ops[i];
	int f = arr.front();
	arr.pop_front();
	calc(ops, arr, f);

	cout << mx << '\n';
	cout << mn << '\n';

	return 0;
}

// https://www.acmicpc.net/problem/14888

/*
Because N is very small, we can do all possible case.
*/

