#include <iostream>
#include <algorithm>

using namespace std;

int N, K, X[50001];

bool solve(int l)
{
	int p = 0, cnt = 1;
	for (int i = 1; i < N; i++)
		if (X[p] + 2 * l < X[i])
		{
			p = i;
			cnt++;
		}
	return cnt <= K;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> K;
	for (int i = 0; i < N; i++) cin >> X[i];
	sort(X, X + N);
	int l = 0, r = 2000000014;
	while (l + 1 < r)
	{
		int m = (l + r) / 2;
		if (solve(m)) r = m;
		else l = m;
	}
	cout << r << '\n';
}

// https://www.acmicpc.net/problem/11973