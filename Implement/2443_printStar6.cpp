#include <iostream>

using namespace std;

int N;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < 2 * N - 1 - i; j++)
		{
			if (j < i) cout << " ";
			else cout << "*";
		}
		cout << '\n';
	}
}

// https://www.acmicpc.net/problem/2443