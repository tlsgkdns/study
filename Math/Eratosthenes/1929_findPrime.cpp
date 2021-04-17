#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <bitset>
#include <cmath>
using namespace std;

int main(void)
{
	int m, n;
	cin >> m >> n;

	bitset<1000001> bit;
	bit.set();
	bit.set(1, false);
	int sq = int(sqrt(n + 1));
	for (int i = 2; i <= sq; i++)
	{
		if (bit.test(i))
			for (int j = i * i; j <= n + 1; j += i)
				bit.set(j, false);
	}

	for (int i = m; i <= n; i++)
	{
		if (bit.test(i))
			cout << i << " " << '\n';
	}
	return 0;
}

// https://www.acmicpc.net/problem/1929