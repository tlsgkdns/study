#include <iostream>

using namespace std;

long long N, C[100001], L[100001], R[100001], ans1 = 0, ans2 = 1e18;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> C[i];
	for (int i = 1; i < N; i++)
	{
		cin >> L[i];
		L[i] += L[i - 1];
	}
	for (int i = 1; i < N; i++)
	{
		cin >> R[i];
		R[i] += R[i - 1];
	}
	for (int i = 1; i <= N; i++)
	{
		long long s = C[i] + L[i - 1] + R[N - 1] - R[i - 1];
		if (s < ans2)
		{
			ans2 = s;
			ans1 = i;
		}
	}
	cout << ans1 << " " << ans2 << '\n';
}

// https://www.acmicpc.net/problem/12841