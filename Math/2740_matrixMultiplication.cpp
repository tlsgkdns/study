#include <iostream>

using namespace std;

int N, M, K;
int arr1[101][101], arr2[101][101], ans[101][101];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> arr1[i][j];
	cin >> M >> K;
	for (int i = 0; i < M; i++)
		for (int j = 0; j < K; j++)
			cin >> arr2[i][j];
	for (int i = 0; i < N; i++)
	{
		for (int k = 0; k < K; k++)
		{
			int s = 0;
			for (int j = 0; j < M; j++)
				s += arr1[i][j] * arr2[j][k];
			ans[i][k] = s;
		}
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < K; j++)
			cout << ans[i][j] << " ";
		cout << '\n';
	}
}

// https://www.acmicpc.net/problem/2740