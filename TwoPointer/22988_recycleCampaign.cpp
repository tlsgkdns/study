#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;
using ll = long long;

int N, ans = 0, h = 0;
ll X, C[100001];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> X;
	for (int i = 0; i < N; i++) cin >> C[i];
	int l = 0, r = N - 1;
	double half = ceil((double)X / 2);
	sort(C, C + N);
	while (r >= 0 && C[r] == X)
	{
		--r;
		++ans;
	}
	while (l < r)
	{
		if (C[l] + C[r] < half)
		{
			++h;
			++l;
		}
		else
		{
			++ans;
			++l;
			--r;
		}
	}
	h += (l == r);
	ans += (h / 3);
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/22988