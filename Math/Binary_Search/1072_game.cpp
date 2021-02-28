

#include <iostream>
#include <vector>

using namespace std;

long long C = 1000000000;

int ratio(double x, double y)
{
	int per = (y * 100 / x);

	return per;
}

long long gamePlay(long long game, long long win)
{
	int rate = ratio(game, win);

	if (rate >= 99) return -1;

	long long high = game;
	long long low = 0;

	while (low <= high)
	{
		long long mid = (high + low) / 2;
		if (rate == ratio(game + mid, win + mid))
			low = mid + 1;
		else
			high = mid - 1;
	}

	return high + 1;
}

int main()
{
	long long x, y;
	cin >> x >> y;

	long long ret = gamePlay(x, y);

	cout << ret << endl;

	return 0;
}


// https://www.acmicpc.net/problem/1072

/*
simple binary search
*/