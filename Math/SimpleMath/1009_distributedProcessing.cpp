#include <iostream>

using namespace std;
int T, A, B;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> T;
	while (T--)
	{
		cin >> A >> B;
		int n = 1;
		for (int i = 0; i < B; i++)
		{
			n *= A;
			n %= 10;
		}
		if (n == 0) n = 10;
		cout << n << '\n';
	}
}

// https://www.acmicpc.net/problem/1009