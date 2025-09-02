#include <iostream>

using namespace std;
int N, Q, X, Y, P[100001], A[100001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		cin >> A[i];
		if (A[i] < A[i - 1])
			P[i] = P[i - 1] + 1;
		else
			P[i] = P[i - 1];
	}
	cin >> Q;
	while (Q--)
	{
		cin >> X >> Y;
		cout << P[Y] - P[X] << '\n';
	}
}

// https://www.acmicpc.net/problem/21318