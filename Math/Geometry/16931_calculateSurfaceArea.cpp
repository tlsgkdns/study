#include <iostream>
#include <algorithm>

using namespace std;

int N, M, ans = 0, B[101][101], tmp1 = 0, tmp2 = 0;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	ans += N * M * 2;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> B[i][j];
	for (int i = 0; i < N; i++)
	{
		ans += B[i][0] * 2;
		for (int j = 1; j < M; j++)
			if (B[i][j - 1] < B[i][j])
				ans += 2 * B[i][j] - 2 * B[i][j - 1];
	}
	for (int j = 0; j < M; j++)
	{
		ans += B[0][j] * 2;
		for (int i = 1; i < N; i++)
			if (B[i - 1][j] < B[i][j])
				ans += 2 * B[i][j] - 2 * B[i - 1][j];
	}
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/16931