#include <iostream>

using namespace std;

int P[50], N, ans = -1, S[50], C[50];

bool chk()
{
	for (int i = 0; i < N; i++)
		if (i % 3 != P[i])
			return false;
	return true;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++) cin >> P[i];
	for (int i = 0; i < N; i++)
		cin >> S[i];
	for (int i = 0; i <= 200000; i++)
	{
		if (chk())
		{
			ans = i;
			break;
		}
		int tmp[50];
		for (int idx = 0; idx < N; idx++) tmp[S[idx]] = P[idx];
		for (int idx = 0; idx < N; idx++) P[idx] = tmp[idx];
	}
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/1091