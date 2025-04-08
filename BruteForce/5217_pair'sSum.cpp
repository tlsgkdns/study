#include <iostream>

using namespace std;

int T, N;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> T;
	while (T--)
	{
		cin >> N;
		cout << "Pairs for " << N << ": ";
		int e = (N % 2 > 0) ? N / 2 : (N / 2) - 1;
		for (int i = 1; i <= e; i++)
		{
			cout << i << " " << N - i;
			if (i != e)
				cout << ", ";
		}
		cout << '\n';
	}
}

// https://www.acmicpc.net/problem/5217