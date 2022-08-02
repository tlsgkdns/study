#include <iostream>

using namespace std;

int N;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = N - 1; i >= 0; i--)
	{
		for (int k = 0; k < i; k++) cout << " ";
		for (int j = 0; j < 2 * (N - 1 - i) + 1; j++)
			cout << "*";
		cout << '\n';
	}
}

// https://www.acmicpc.net/problem/2442