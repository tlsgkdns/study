#include <iostream>

using namespace std;

int cave[200001], h1[500001], h2[500001];
int N, H, hei, s = 0, ans = 200002, cnt = 0;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> H;
	for (int i = 0; i < N; i++)
	{
		cin >> hei;
		if (i % 2 == 0)
		{
			h1[hei]++;
			s++;
		}
		else
		{
			h2[H - hei]++;
		}
	}
	for (int h = 1; h <= H; h++)
	{
		if (ans > s)
		{
			cnt = 1;
			ans = s;
		}
		else if (ans == s)
			cnt++;
		s = (s - h1[h] + h2[h]);
	}
	cout << ans << " " << cnt << '\n';
}

// https://www.acmicpc.net/problem/3020