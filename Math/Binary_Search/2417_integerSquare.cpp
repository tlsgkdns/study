#include <iostream>

using namespace std;
unsigned long long N, l = 1, r, m;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N; r = N;
	if (N > 0)
	{
		for (int it = 0; it < 100; it++)
		{
			m = (l + r) / 2;
			if (m > (N / m)) r = m;
			else l = m;
		}
	}
	else l = 0;
	if (l * l < N) l = r;
	cout << l << '\n';
}

// https://www.acmicpc.net/problem/2417