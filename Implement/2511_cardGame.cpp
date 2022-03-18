#include <iostream>

using namespace std;

int A[10], B[10];
int win = 0, a = 0, b = 0;
int main()
{
	for (int i = 0; i < 10; i++) cin >> A[i];
	for (int i = 0; i < 10; i++) cin >> B[i];
	for (int i = 0; i < 10; i++)
	{
		if (A[i] < B[i])
		{
			win = -1;
			b += 3;
		}
		else if (A[i] > B[i])
		{
			win = 1;
			a += 3;
		}
		else
		{
			a++;
			b++;
		}
	}
	cout << a << " " << b << '\n';
	if (a > b) cout << "A\n";
	else if (a < b) cout << "B\n";
	else if (win == 1) cout << "A\n";
	else if (win == -1) cout << "B\n";
	else cout << "D\n";
}

// https://www.acmicpc.net/problem/2511