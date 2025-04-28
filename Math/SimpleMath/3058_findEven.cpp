#include <iostream>
#include <algorithm>

using namespace std;
int T, N, A;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> T;
	while (T--)
	{
		int s1 = 0, s2 = 1e9;
		for (int i = 0; i < 7; i++)
		{
			cin >> A;
			if (A % 2 == 0)
			{
				s1 += A;
				s2 = min(s2, A);
			}
		}
		cout << s1 << " " << s2 << '\n';
	}
}

// https://www.acmicpc.net/problem/3058