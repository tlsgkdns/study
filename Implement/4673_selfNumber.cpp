#include <iostream>
#include <algorithm>

using namespace std;

bool v[10001];
int getNum(int n)
{
	int s = n;
	while (n > 0)
	{
		s += (n % 10);
		n /= 10;
	}
	return s;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	for (int n = 1; n <= 10000; n++)
	{
		int num = n;
		while (true)
		{
			num = getNum(num);
			if (num > 10000 || v[num]) break;
			v[num] = true;
		}
	}
	for (int i = 1; i <= 10000; i++)
		if (!v[i])
			cout << i << '\n';
}

// https://www.acmicpc.net/problem/4673