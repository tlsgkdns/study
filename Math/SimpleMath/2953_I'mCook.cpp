#include <iostream>
#include <algorithm>
using namespace std;
int S, ans = 0, idx = -1;
int main()
{
	for (int i = 0; i < 5; i++)
	{
		int s = 0;
		for (int j = 0; j < 4; j++)
		{
			cin >> S;
			s += S;
		}
		if (ans < s)
		{
			idx = i + 1;
			ans = s;
		}
	}
	cout << idx << " " << ans << '\n';
}

// https://www.acmicpc.net/problem/2953