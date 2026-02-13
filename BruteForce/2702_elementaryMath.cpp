#include <iostream>
#include <algorithm>

using namespace std;

int T, A, B;

int main()
{
	cin >> T;
	while (T--)
	{
		cin >> A >> B;
		int m = min(A, B), g = 1;
		for (int n = m; n >= 1; n--)
		{
			if (A % n == 0 && B % n == 0)
			{
				g = n;
				break;
			}
		}
		cout << A * B / g << " " << g << '\n';
	}
}

// https://www.acmicpc.net/problem/2702