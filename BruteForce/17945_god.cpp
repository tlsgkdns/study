#include <iostream>

using namespace std;
int A, B;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> A >> B;
	for (int a = -2000; a <= 2000; a++)
		for (int b = a; b <= 2000; b++)
		{
			if (a * b == B && a + b == -2 * A)
			{
				if (a == b) cout << a << '\n';
				else cout << a << " " << b << '\n';
			}
		}
}

// https://www.acmicpc.net/problem/17945