#include <iostream>
#include <cmath>

using namespace std;

int N, M, D[100001], now = 0, ans = 0, A;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	for (int i = 1; i < N; i++)
	{
		cin >> D[i];
		D[i] += D[i - 1];
	}
	for (int i = 0; i < M; i++)
	{
		cin >> A;
		ans += abs(D[now + A] - D[now]);
		ans %= 100000;
		now += A;
	}
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/5560