#include <iostream>

using namespace std;

int N, M, ans = 0;
string B[51];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < N; i++)cin >> B[i];
	for (int i = 0; i < N; i++)
	{
		bool f = false;
		for (int j = 0; j < M; j++)
		{
			if (B[i][j] == '|')
			{
				ans += f;
				f = false;
			}
			else
			{
				f = true;
			}
		}
		ans += f;
	}
	for (int j = 0; j < M; j++)
	{
		bool f = false;
		for (int i = 0; i < N; i++)
		{
			if (B[i][j] == '-')
			{
				ans += f;
				f = false;
			}
			else
			{
				f = true;
			}
		}
		ans += f;
	}
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/1388