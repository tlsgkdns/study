#include <iostream>
#include <algorithm>
using namespace std;

int N, M, A[301], l = 0, r = 1000000007;

bool solve(int limit)
{
	int cnt = 1, s = A[0];
	for (int i = 1; i < N; i++)
	{
		if (s + A[i] > limit)
		{
			++cnt;
			s = A[i];
		}
		else
			s += A[i];
	}
	return cnt <= M;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		cin >> A[i];
		l = max(l, A[i]);
	}
	--l;
	while (l + 1 < r)
	{
		int m = (l + r) / 2;
		if (solve(m)) r = m;
		else l = m;
	}
	cout << r << '\n';
	int s = A[0], l = 1, cnt = 1;
	for (int i = 1; i < N; i++)
	{
		if (A[i] + s > r || N - i == M - cnt)
		{
			cout << l << " ";
			s = A[i];
			l = 1;
			++cnt;
		}
		else
		{
			++l;
			s += A[i];
		}
	}
	cout << l << '\n';
}

// https://www.acmicpc.net/problem/2613