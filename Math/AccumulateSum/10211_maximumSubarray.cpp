#include <iostream>
#include <algorithm>
using namespace std;

int T, N, X, A[1001];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> T;
	while (T--)
	{
		cin >> N;
		for (int i = 1; i <= N; i++)
		{
			cin >> X;
			A[i] = A[i - 1] + X;
		}
		int ans = -1000000007;
		for (int i = 1; i <= N; i++)
			for (int j = 0; j < i; j++)
				ans = max(ans, A[i] - A[j]);
		cout << ans << '\n';
	}
}

// https://www.acmicpc.net/problem/10211