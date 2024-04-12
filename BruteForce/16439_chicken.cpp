#include <iostream>
#include <algorithm>
using namespace std;
int N, M, ans = 0;
int L[31][31];
int main()
{
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> L[i][j];
	for (int i = 0; i < M; i++)
		for (int j = i + 1; j < M; j++)
			for (int k = j + 1; k < M; k++)
			{
				int s = 0;
				for (int idx = 0; idx < N; idx++)
					s += max(L[idx][i], max(L[idx][j], L[idx][k]));
				ans = max(s, ans);
			}
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/16439