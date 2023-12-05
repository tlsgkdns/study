#include <iostream>

using namespace std;

int S1, P, S2 = 0;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> S1;
	for (int i = 0; i < 9; i++)
	{
		cin >> P;
		S2 += P;
	}
	cout << S1 - S2 << '\n';
}

// https://www.acmicpc.net/problem/5565