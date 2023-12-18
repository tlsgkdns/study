#include <iostream>

using namespace std;
using ll = long long;
int N, M, T, C[100001], K;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> T;
	while (T--)
	{
		cin >> N >> M >> K;
		int ans = 0, S = 0;
		for (int i = 0; i < N; i++) cin >> C[i];
		for (int a = 0; a < M; a++) S += C[a];
		ans += (S < K);
		if (M < N)
		{
			for (int i = 1; i < N; i++)
			{
				S -= C[i - 1];
				S += C[(i + M - 1) % N];
				ans += (S < K);
			}
		}

		cout << ans << '\n';
	}
}

// https://www.acmicpc.net/problem/13422