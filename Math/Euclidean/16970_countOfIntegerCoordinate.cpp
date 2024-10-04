#include <iostream>
#include <cmath>

using namespace std;

int N, K, M, ans = 0;

int euc(int a, int b)
{
	if (a < b) return euc(b, a);
	if (b == 0) return a;
	return euc(b, a % b);
}
int getCnt(int r1, int c1, int r2, int c2)
{
	if (r1 == r2) return abs(c1 - c2) + 1;
	if (c1 == c2) return abs(r1 - r2) + 1;
	int a = abs(r1 - r2), b = abs(c1 - c2);
	int e = euc(a, b);
	if (e == 0) return 2;
	return e + 1;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M >> K;
	for (int r1 = 0; r1 <= N; r1++)
		for (int c1 = 0; c1 <= M; c1++)
			for (int r2 = 0; r2 <= N; r2++)
				for (int c2 = 0; c2 <= M; c2++)
					if (r1 != r2 || c1 != c2)
						ans += (getCnt(r1, c1, r2, c2) == K);
	ans /= 2;
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/16970