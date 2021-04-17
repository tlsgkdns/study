#include <iostream>
#include <vector>

using namespace std;

vector<long long> green;
long long s, c;
long long all = 0;

bool canChop(long long l)
{
	long long sum = 0;
	for (int i = 0; i < s; i++)
	{
		sum += green[i] / l;
		if (sum >= c) break;
	}

	return sum >= c;
}

long long ramen()
{
	long long l = 0, h = 1000000001;
	for (int it = 0; it < 100; it++)
	{
		long long mid = (l + h) / 2;
		if (canChop(mid))
			l = mid;
		else
			h = mid;
	}

	return all - (l * c);
}
int main()
{
	cin >> s >> c;
	green.resize(s);
	for (int i = 0; i < s; i++)
	{
		cin >> green[i];
		all += green[i];
	}

	cout << ramen() << endl;
	return 0;
}

// https://www.acmicpc.net/problem/14627