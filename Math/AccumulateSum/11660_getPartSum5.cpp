#include <iostream>

using namespace std;

int N, M, X1, Y1, X2, Y2;
int table[1025][1025], psum[1025][1025];

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(NULL); cin.tie(NULL);
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
		{
			cin >> table[i][j];
			psum[i][j] = psum[i][j - 1] + psum[i - 1][j] + table[i][j] - psum[i - 1][j - 1];
		}
	for (int i = 0; i < M; i++)
	{
		cin >> X1 >> Y1 >> X2 >> Y2;
		cout << psum[X2][Y2] - psum[X2][Y1 - 1] - psum[X1 - 1][Y2] + psum[X1 - 1][Y1 - 1] << '\n';
	}
}

// https://www.acmicpc.net/problem/11660