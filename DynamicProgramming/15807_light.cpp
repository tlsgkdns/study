#include <iostream>

using namespace std;

const int MAX = 3005;
int N, X, Y, P, G[MAX][MAX], S[MAX][MAX];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> X >> Y;
		G[Y + 1502][X + 1502]++;
	}
	for (int i = 2; i < MAX; i++)
		for (int j = 1; j < MAX; j++)
		{
			if (j == 1) S[i][j] = S[i - 1][j + 1] + G[i][j] + G[i - 1][j];
			else if (j == MAX - 1) S[i][j] = S[i - 1][j - 1] + G[i][j] + G[i - 1][j];
			else S[i][j] = S[i - 1][j - 1] + S[i - 1][j + 1] - S[i - 2][j] + G[i][j] + G[i - 1][j];
		}
	cin >> P;
	while (P--)
	{
		cin >> X >> Y;
		cout << S[Y + 1502][X + 1502] << '\n';
	}
}

// https://www.acmicpc.net/problem/15807