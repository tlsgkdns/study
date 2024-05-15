#include <iostream>

using namespace std;

int S, P, C[4], cnt[4], ans = 0;
string D;

int getIdx(char c)
{
	if (c == 'A') return 0;
	if (c == 'C') return 1;
	if (c == 'G') return 2;
	return 3;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> S >> P;
	cin >> D;
	for (int i = 0; i < 4; i++) cin >> C[i];
	for (int i = 0; i < P; i++)
	{
		++cnt[getIdx(D[i])];
	}
	int c = 1;
	for (int i = 0; i < 4; i++)
	{
		if (C[i] > cnt[i])
		{
			c = 0;
			break;
		}
	}
	ans += c;
	for (int i = 0; i + P < S; i++)
	{
		--cnt[getIdx(D[i])];
		++cnt[getIdx(D[i + P])];
		c = 1;
		for (int idx = 0; idx < 4; idx++)
		{
			if (C[idx] > cnt[idx])
			{
				c = 0;
				break;
			}
		}
		ans += c;
	}
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/12891