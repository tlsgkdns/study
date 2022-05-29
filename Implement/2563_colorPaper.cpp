#include <iostream>

using namespace std;

int paper[101][101], N, Y, X, ans = 0;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> Y >> X;
		for (int y = Y; y < Y + 10; y++)
			for (int x = X; x < X + 10; x++)
				paper[y][x] = 1;
	}
	for (int i = 1; i <= 100; i++)
		for (int j = 1; j <= 100; j++)
			ans += paper[i][j];
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/2563