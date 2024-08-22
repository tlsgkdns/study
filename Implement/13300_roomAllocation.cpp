#include <iostream>

using namespace std;

int N, K, S, Y, R[2][7], ans = 0;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> K;
	for (int i = 0; i < N; i++)
	{
		cin >> S >> Y;
		R[S][Y]++;
	}
	for (int i = 0; i < 2; i++)
		for (int j = 1; j <= 6; j++)
			ans += (R[i][j] / K) + (R[i][j] % K > 0);
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/13300