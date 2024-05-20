#include <iostream>

using namespace std;
int N, M, K, a, b, c, d, J[1001][1001], O[1001][1001], I[1001][1001];
char A[1001][1001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	cin >> K;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
		{
			cin >> A[i][j];
			O[i][j] = O[i - 1][j] + O[i][j - 1] - O[i - 1][j - 1] + (A[i][j] == 'O');
			J[i][j] = J[i - 1][j] + J[i][j - 1] - J[i - 1][j - 1] + (A[i][j] == 'J');
			I[i][j] = I[i - 1][j] + I[i][j - 1] - I[i - 1][j - 1] + (A[i][j] == 'I');
		}
	while (K--)
	{
		cin >> a >> b >> c >> d;
		cout << J[c][d] - J[a - 1][d] - J[c][b - 1] + J[a - 1][b - 1] << " "
			<< O[c][d] - O[a - 1][d] - O[c][b - 1] + O[a - 1][b - 1] << " "
			<< I[c][d] - I[a - 1][d] - I[c][b - 1] + I[a - 1][b - 1] << '\n';
	}
}

// https://www.acmicpc.net/problem/5549