#include <iostream>

using namespace std;

int N, A[21][21], ans = 0, T[21][21];
bool f = false;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{
			cin >> A[i][j];
			T[i][j] = A[i][j];
		}
	for (int k = 0; k < N && !f; k++)
		for (int i = 0; i < N && !f; i++)
			for (int j = 0; j < N && !f; j++)
			{
				if (i == j || j == k || i == k) continue;
				if (A[i][j] > A[i][k] + A[k][j])
				{
					f = true;
					break;
				}
				if (A[i][j] == A[i][k] + A[k][j]) T[i][j] = 0;
			}
	if (f) cout << -1 << '\n';
	else
	{
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				ans += T[i][j];
		ans /= 2;
		cout << ans << '\n';
	}
}

// https://www.acmicpc.net/problem/1507