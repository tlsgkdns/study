#include <iostream>

using namespace std;

int N, M, A;
int ans[101][101];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> ans[i][j];
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
		{
			cin >> A;
			ans[i][j] += A;
		}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
			cout << ans[i][j] << " ";
		cout << '\n';
	}
}

// https://www.acmicpc.net/problem/2738