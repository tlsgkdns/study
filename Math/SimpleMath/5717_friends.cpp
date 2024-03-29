#include <iostream>

using namespace std;

int M, F;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	while (true)
	{
		cin >> M >> F;
		if (M == 0 && F == 0) break;
		cout << M + F << '\n';
	}
}

// https://www.acmicpc.net/problem/5717