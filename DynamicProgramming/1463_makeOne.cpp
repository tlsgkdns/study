#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

#define MAX 1000001;

using namespace std;

int cache[1000001];

int one(int x)
{
	int& ret = cache[x];
	if (ret != -1) return ret;
	int stepOne = (x % 3 == 0) ? one(x / 3) + 1 : MAX;
	int stepTwo = (x % 2 == 0) ? one(x / 2) + 1 : MAX;

	ret = min(stepOne, stepTwo);
	ret = min(ret, one(x - 1) + 1);

	return ret;
}

int main(void)
{
	memset(cache, -1, sizeof(cache));
	cache[1] = 0;
	int x;
	cin >> x;
	int ans = one(x);
	cout << ans << endl;

	return 0;
}

// https://www.acmicpc.net/problem/1463
/*
standard dynamic programming
*/