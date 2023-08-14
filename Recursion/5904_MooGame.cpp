#include <iostream>
using namespace std;
int N, K = 0, S = 0;
bool solve(int s, int n, int k)
{
	int L = (s - (k + 2)) / 2;
	if (L + k + 2 < n) return solve(s - L - k - 2, n - L - k - 2, k - 1);
	if (n <= L) return solve(L, n, k - 1);
	return (L + 1 == n);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	while (S < N) S = ((K++) + 3) + 2 * S;
	if (solve(S, N, K)) cout << "m" << '\n';
	else cout << "o" << '\n';
}

// https://www.acmicpc.net/problem/5904