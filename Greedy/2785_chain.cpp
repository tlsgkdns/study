#include <iostream>
#include <algorithm>

using namespace std;

int N, L[500001], ans = 0;
long long s = 0;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++) cin >> L[i];
	int l = 0, r = N - 1;
	sort(L, L + N);
	while (l < r)
	{
		if (s > 0)
		{
			s--;
			++ans;
			--r;
		}
		else
		{
			s += L[l++];
		}
	}
	ans += (s > 0);
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/2785