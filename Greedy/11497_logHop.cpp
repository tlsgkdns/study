#include <iostream>
#include <algorithm>
using namespace std;

int T, N, L[10001];
const int INF = 1000000007;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> T;
	while (T--)
	{
		cin >> N;
		for (int i = 0; i < N; i++)
			cin >> L[i];
		sort(L, L + N);
		int l = L[0], r = L[0], ans = 0;
		bool f = false;
		for (int i = 1; i < N; i++)
		{
			if (f)
			{
				ans = max(ans, L[i] - r);
				r = L[i];
			}
			else
			{
				ans = max(ans, L[i] - l);
				l = L[i];
			}
			f = !f;
		}
		cout << ans << '\n';
	}
}

// https://www.acmicpc.net/problem/11497