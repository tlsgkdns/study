#include <iostream>

using namespace std;
int N, A[100001], M, L, R;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		cin >> A[i];
		A[i] += A[i - 1];
	}
	cin >> M;
	while (M--)
	{
		cin >> L >> R;
		cout << A[R] - A[L - 1] << '\n';
	}
}

// https://www.acmicpc.net/problem/11441