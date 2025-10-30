#include <iostream>

using namespace std;
int N;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < 2 * N; i++)
	{
		for (int j = 0; j < N; j++)
			if (i % 2 == j % 2)
				cout << "*";
			else
				cout << " ";
		cout << '\n';
	}
}

// https://www.acmicpc.net/problem/10996