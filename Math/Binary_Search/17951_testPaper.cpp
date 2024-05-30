#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int N, K, X[100001];

bool solve(int cost)
{
	int cnt = 0, s = 0;
	for (int i = 0; i < N; i++)
	{
		s += X[i];
		if (s >= cost)
		{
			++cnt;
			s = 0;
		}
	}
	return cnt >= K;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> K;
	for (int i = 0; i < N; i++) cin >> X[i];
	int l = 0, r = 1000000007;
	while (l + 1 < r)
	{
		int m = (l + r) / 2;
		if (solve(m)) l = m;
		else r = m;
	}
	cout << l << '\n';
}

// https://www.acmicpc.net/problem/17951