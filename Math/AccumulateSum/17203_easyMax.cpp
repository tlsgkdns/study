#include <iostream>
#include <cmath>

using namespace std;

int N, Q, P[1001], A[1001], S, E;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> Q;
	for (int i = 1; i <= N; i++)
	{
		cin >> A[i];
		P[i] = abs(A[i] - A[i - 1]) + P[i - 1];
	}
	while (Q--)
	{
		cin >> S >> E;
		cout << P[E] - P[S] << '\n';
	}
}

// https://www.acmicpc.net/problem/17203