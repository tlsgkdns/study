#include <iostream>
#include <algorithm>
using namespace std;

int N, A[51], ans = 0, M = 0;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> A[i];
		int cnt = 0;
		while (A[i] > 0)
		{
			if (A[i] % 2 > 0) ++ans;
			A[i] /= 2;
			++cnt;
		}
		M = max(M, cnt - 1);
	}
	ans += M;
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/12931