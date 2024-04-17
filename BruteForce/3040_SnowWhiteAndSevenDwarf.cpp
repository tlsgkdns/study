#include <iostream>

using namespace std;

int R[9], s = 0;
bool v[9];
int main()
{
	for (int i = 0; i < 9; i++)
	{
		cin >> R[i];
		s += R[i];
	}
	s -= 100;
	for (int i = 0; i < 9; i++)
		for (int j = i + 1; j < 9; j++)
		{
			if (R[i] + R[j] == s)
			{
				v[i] = v[j] = true;
				break;
			}
		}
	for (int i = 0; i < 9; i++)
		if (!v[i]) cout << R[i] << '\n';
}

// https://www.acmicpc.net/problem/3040