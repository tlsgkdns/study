#include <iostream>

using namespace std;

int N;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	int n = N;
	for (int i = 1; i * 10 < n; i *= 10)
	{
		N += (i * 5);
		N /= (i * 10);
		N *= (i * 10);
	}
	cout << N << '\n';
}

// https://www.acmicpc.net/problem/2033