#include <iostream>
#include <algorithm>

using namespace std;

int K, C, M, N;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> K >> C;
	for (int i = 0; i < C; i++)
	{
		cin >> M >> N;
		if (M <= N)
		{
			int r = K - N + 1;
			if (M + r >= N) cout << 1 << '\n';
			else cout << 0 << '\n';
		}
		else
		{
			int r = K - M + 1;
			M--;
			if (N + r >= M) cout << 1 << '\n';
			else cout << 0 << '\n';
		}
	}
}

// https://www.acmicpc.net/problem/10837