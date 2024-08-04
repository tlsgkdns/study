#include <iostream>

using namespace std;
using ll = long long;
int M, N, L[1000001];

bool solve(int l)
{
	ll ret = 0;
	for (int i = 0; i < N; i++)
		ret += (L[i] / l);
	return ret >= M;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> M >> N;
	for (int i = 0; i < N; i++) cin >> L[i];
	int l = 0, r = 1000000007;
	while (l + 1 < r)
	{
		int m = (l + r) / 2;
		if (solve(m)) l = m;
		else r = m;
	}
	cout << l << '\n';
}

// https://www.acmicpc.net/problem/16401