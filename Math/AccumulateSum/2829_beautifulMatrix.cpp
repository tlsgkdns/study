#include <iostream>
#include <algorithm>

using namespace std;

int N, A[402][402], B[402][402], M, ans = -1000000007;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
		{
			cin >> M;
			A[i][j] = A[i - 1][j - 1] + M;
			B[i][j] = B[i - 1][j + 1] + M;
		}

	for (int n = 1; n <= N; n++)
		for (int y = 0; y + n <= N; y++)
			for (int x = 0; x + n <= N; x++)
				ans = max(ans, (A[y + n][x + n] - A[y][x]) - (B[y + n][x + 1] - B[y][x + n + 1]));
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/2829