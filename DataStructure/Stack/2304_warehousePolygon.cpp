#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int MAX = 1001;
int hs[MAX], hm[MAX];
int N, L, H, s = 1001, e = 0;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> L >> H;
		hs[L] = H;
		e = max(L, e);
		s = min(L, s);
	}
	hm[e] = hs[e];
	for (int i = e - 1; i >= s; i--)
		hm[i] = max(hm[i + 1], hs[i]);
	int height = 0, ans = 0;
	for (int i = s; i <= e; i++)
	{
		if (height < hs[i])
			height = hs[i];
		else if (height > hm[i])
			height = hm[i];
		ans += height;
	}
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/2304