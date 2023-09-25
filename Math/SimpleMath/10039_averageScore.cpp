#include <iostream>

using namespace std;

int S = 0, A;
int main()
{
	for (int i = 0; i < 5; i++)
	{
		cin >> A;
		if (A <= 40) A = 40;
		S += A;
	}
	S /= 5;
	cout << S << '\n';
}

// https://www.acmicpc.net/problem/10039