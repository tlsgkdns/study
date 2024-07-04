#include <iostream>

using namespace std;

int N, K, ans[100001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> K;
	if (N <= K) cout << "Impossible\n";
	else
	{
		if ((N - K) % 2 > 0)
		{
			for (int i = 1; i <= K + 1; i++)
				ans[i] = i;
			for (int i = K + 2; i + 1 <= N; i += 2)
			{
				ans[i] = i + 1;
				ans[i + 1] = i;
			}
		}
		else
		{
			for (int i = 1; i < N - K; i += 2)
			{
				ans[i] = i + 1;
				ans[i + 1] = i;
			}
			for (int i = N - K + 1; i <= N; i++)
				ans[i] = i;
		}
		for (int i = 1; i <= N; i++)
			cout << ans[i] << " ";
		cout << '\n';
	}
}

// https://www.acmicpc.net/problem/13018