#include <iostream>

using namespace std;

int A, B, N;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> A >> B >> N;
	A %= B;
	for (int i = 0; i < N - 1; i++)
	{
		A *= 10;
		A %= B;
	}
	cout << (A * 10) / B << '\n';
}

// https://www.acmicpc.net/problem/1312