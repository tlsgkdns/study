#include <iostream>

using namespace std;

int N;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	while (true)
	{
		cin >> N;
		if (N == 0) break;
		while (N >= 10)
		{
			int s = 0;
			while (N > 0)
			{
				s += (N % 10);
				N /= 10;
			}
			N = s;
		}
		cout << N << '\n';
	}
}

// https://www.acmicpc.net/problem/2145