#include <iostream>

using namespace std;
int rev[10][10]
= { {0, 4, 3, 3, 4, 3, 2, 3, 1, 2},
	{4, 0, 5, 3, 2, 5, 6, 1, 5, 4},
	{3, 5, 0, 2, 5, 4, 3, 4, 2, 3},
	{3, 3, 2, 0, 3, 2, 3, 2, 2, 1},
	{4, 2, 5, 3, 0, 3, 4, 3, 3, 2},
	{3, 5, 4, 2, 3, 0, 1, 4, 2, 1},
	{2, 6, 3, 3, 4, 1, 0, 5, 1, 2},
	{3, 1, 4, 2, 3, 4, 5, 0, 4, 3},
	{1, 5, 2, 2, 3, 2, 1, 4, 0, 1},
	{2, 4, 3, 1, 2, 1, 2, 3, 1, 0} };
int N, K, P, X;
int changeNum(int from, int to)
{
	int ret = 0, l = from, r = to;
	while (l > 0 || r > 0)
	{
		ret += rev[l % 10][r % 10];
		l /= 10;
		r /= 10;
	}
	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> K >> P >> X;
	int ans = 0;
	for (int F = 1; F <= N; F++)
	{
		if (F == X) continue;
		int r = changeNum(X, F);
		ans += (r <= P);
	}
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/22251