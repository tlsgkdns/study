#include <iostream>
#include <algorithm>

using namespace std;
const int MAX = 1000001;
int N, C[MAX], D[MAX], ans = 0, t = 0;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> C[i] >> D[i];
	}
	for (int c = 0; c < MAX; c++)
	{
		int s = 0;
		for (int i = 0; i < N; i++)
			if (C[i] >= c && c >= D[i])
				s += (c - D[i]);
		if (t < s)
		{
			ans = c;
			t = s;
		}
	}
	if (ans < 0) ans = 0;
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/1487