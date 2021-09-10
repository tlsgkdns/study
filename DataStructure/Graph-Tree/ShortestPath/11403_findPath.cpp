#include <iostream>

using namespace std;

const int INF = 1000000000;
bool G[101][101];
int N;
int main()
{
	bool bo;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{
			cin >> bo;
			G[i][j] = bo;
		}

	for (int k = 0; k < N; k++)
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				if (G[i][k] && G[k][j])
					G[i][j] = true;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			cout << G[i][j] << " ";
		cout << '\n';
	}
}
// https://www.acmicpc.net/problem/11403