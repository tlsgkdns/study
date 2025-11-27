#include <iostream>

using namespace std;
int N;
long long ans = 0, P[100001], X[100001];
int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(NULL); cin.tie(NULL);
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		cin >> X[i];
		P[i] = P[i - 1] + X[i];
	}
	for (int i = 2; i <= N; i++)
	{
		ans += P[i - 1] * X[i];
	}
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/14929