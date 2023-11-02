#include <iostream>

using namespace std;

int R, C, Q, r1, c1, r2, c2, K, P[1002][1002];

int main()
{
	cin >> R >> C >> Q;
	for (int i = 1; i <= R; i++)
		for (int j = 1; j <= C; j++)
		{
			cin >> K;
			P[i][j] = K + P[i - 1][j] + P[i][j - 1] - P[i - 1][j - 1];
		}
	while (Q--)
	{
		cin >> r1 >> c1 >> r2 >> c2;
		cout << (P[r2][c2] - P[r1 - 1][c2] - P[r2][c1 - 1] + P[r1 - 1][c1 - 1]) / ((r2 - r1 + 1) * (c2 - c1 + 1)) << '\n';
	}
}


// https://www.acmicpc.net/problem/16507