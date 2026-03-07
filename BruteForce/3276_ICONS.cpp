#include <iostream>

using namespace std;
int N, p = 10001, a1 = 0, a2 = 0;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int r = 1; r <= 100; r++)
		for (int c = r; c <= 100; c++)
			if (r * c >= N && p > c + r)
			{
				p = c + r;
				a1 = r; a2 = c;
			}
	cout << a1 << " " << a2 << '\n';
}

// https://www.acmicpc.net/problem/3276