#include <iostream>
#include <algorithm>
using namespace std;
int N, L, M, ans = 0, X[101], Y[101];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> L >> M;
	for (int i = 0; i < M; i++) cin >> X[i] >> Y[i];
	for (int x = 0; x < M; x++)
		for (int y = 0; y < M; y++)
			for (int l = 1; l < (L / 2); l++)
			{
				int nx = X[x] + l;
				int ny = Y[y] + (L / 2) - l;
				int cnt = 0;
				for (int idx = 0; idx < M; idx++)
					cnt += (X[idx] <= nx && Y[idx] <= ny && X[idx] >= X[x] && Y[idx] >= Y[y]);
				ans = max(ans, cnt);
			}
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/7573