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
		if (i % 2 > 0) cout << " ";
		for (int j = 0; j < N; j++)
			cout << "* ";
		cout << '\n';
	}
}

// https://www.acmicpc.net/problem/10995