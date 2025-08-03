#include <iostream>

using namespace std;

long long N, ans = 0, F[46], X;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	F[0] = F[1] = 1;
	for (int i = 2; i <= 45; i++)
		F[i] = F[i - 1] + F[i - 2];
	for (int i = 0; i < N; i++)
	{
		cin >> X;
		cout << F[X] << '\n';
	}
}

// https://www.acmicpc.net/problem/26529