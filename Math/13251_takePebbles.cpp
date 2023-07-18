#include <iostream>

using namespace std;

int M, K, B[51], S = 0;
double ans = 0.0;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> M;
	for (int i = 0; i < M; i++)
	{
		cin >> B[i];
		S += B[i];
	}
	cin >> K;
	for (int i = 0; i < M; i++)
	{
		if (B[i] < K) continue;
		double p = 1.0;
		for (int j = 0; j < K; j++)
			p *= (double)(B[i] - j) / (double)(S - j);
		ans += p;
	}
	cout.precision(11);
	cout << fixed;
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/13251