#include <iostream>
#include <algorithm>
using namespace std;

int N, M, ans = 1;
int R[51][51];
char ch;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
		{
			cin >> ch;
			R[i][j] = ch - '0';
		}
	for (int s = 1; s < min(N, M); s++)
		for (int y = 0; y < N - s; y++)
			for (int x = 0; x < M - s; x++)
				if (R[y][x] == R[y + s][x + s] && R[y][x] == R[y + s][x] && R[y][x] == R[y][x + s])
					ans = (s + 1);
	cout << ans * ans << '\n';
}

// https://www.acmicpc.net/problem/1051