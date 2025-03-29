#include <iostream>
using namespace std;

char B[31][31], ans = ' ';
int N;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> B[i][j];
	for (int i = 0; i < N && ans == ' '; i++)
		for (int j = 0; j < N && ans == ' '; j++)
		{
			if (B[i][j] == '.') continue;
			if (i + 2 <= N - 1 && B[i][j] == B[i + 1][j] && B[i][j] == B[i + 2][j])
			{
				ans = B[i][j];
				break;
			}
			if (j + 2 <= N - 1 && B[i][j] == B[i][j + 1] && B[i][j] == B[i][j + 2])
			{
				ans = B[i][j];
				break;
			}
			if (i + 2 <= N - 1 && j + 2 <= N - 1 && B[i][j] == B[i + 1][j + 1] && B[i][j] == B[i + 2][j + 2])
			{
				ans = B[i][j];
				break;
			}
			if (i + 2 <= N - 1 && j - 2 >= 0 && B[i][j] == B[i + 1][j - 1] && B[i][j] == B[i + 2][j - 2])
			{
				ans = B[i][j];
				break;
			}
		}
	if (ans == ' ') cout << "ongoing\n";
	else cout << ans << '\n';
}

// https://www.acmicpc.net/problem/3024