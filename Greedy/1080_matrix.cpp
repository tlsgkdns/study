#include <iostream>
#include <algorithm>

using namespace std;
int N, M, ans = 0;
char ch;
bool A[51][51], B[51][51];
int dy[9] = { -1, -1, -1, 0, 0, 0, 1, 1, 1 };
int dx[9] = { -1, 0, 1, -1, 0, 1, -1, 0, 1 };
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
		{
			cin >> ch;
			A[i][j] = ch - '0';
		}
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
		{
			cin >> ch;
			B[i][j] = ch - '0';
		}
	for (int i = 1; i < N - 1; i++)
		for (int j = 1; j < M - 1; j++)
		{
			if (A[i - 1][j - 1] != B[i - 1][j - 1])
			{
				for (int d = 0; d < 9; d++)
				{
					int y = i + dy[d];
					int x = j + dx[d];
					B[y][x] = !B[y][x];
				}
				++ans;
			}

		}
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			if (A[i][j] != B[i][j])
			{
				ans = -1;
				break;
			}
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/1080