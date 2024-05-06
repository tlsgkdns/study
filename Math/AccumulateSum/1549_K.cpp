#include <iostream>
#include <cmath>
using namespace std;

int N;
long long A[3001], P[3001], K = 0, ans = 1000000000000000000;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> A[i];
	for (int i = 1; i <= N; i++) P[i] = P[i - 1] + A[i];
	for (int k = 0; k <= N; k++)
		for (int i = 1; i + k <= N; i++)
			for (int j = i + k + 1; j + k <= N; j++)
			{
				long long now = abs(P[i + k] - P[i - 1] - P[j + k] + P[j - 1]);
				if (now < ans)
				{
					ans = now;
					K = k;
				}
				else if (now == ans && k > K)
				{
					K = k;
				}
			}
	cout << K + 1 << '\n' << ans << '\n';
}

// https://www.acmicpc.net/problem/1549