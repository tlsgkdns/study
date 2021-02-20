#include <iostream>
#include <string.h>
#include <algorithm>

using namespace std;


int cache[5001];

int leastBag(int sugar)
{
	if (sugar < 0) return -2;
	int& ret = cache[sugar];
	if (sugar == 0)
	{
		ret = 0;
		return ret;
	}
	if (ret != -1) return ret;
	int minus3 = leastBag(sugar - 3);
	int minus5 = leastBag(sugar - 5);
	if (minus3 == -2 && minus5 == -2)
	{
		ret = -2;
	}
	else if (minus3 == -2 || minus5 == -2)
	{
		ret = ((minus3 == -2) ? minus5 : minus3) + 1;
	}
	else
	{
		ret = min(minus3, minus5) + 1;
	}

	return ret;
}

int main(void)
{
	memset(cache, -1, sizeof(cache));

	int sugar;
	cin >> sugar;
	int answer = (leastBag(sugar) != -2) ? leastBag(sugar) : -1;
	cout << answer << endl;
	return 0;
}

// https://www.acmicpc.net/problem/2839
/*
-1 unchecked.
-2 impossible.
Maybe greedy will helpful than dynamic?
*/