#include <iostream>
#include <cstring>
#include <queue>

using namespace std;
int v[512];
int T, b = (1 << 9) - 1;
char ch;
int f[8][3] = { {0, 1, 2}, {3, 4, 5}, {6, 7, 8}, {0, 4, 8}, {2, 4, 6}, {0, 3, 6}, {1, 4, 7}, {2, 5, 8} };
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> T;
	while (T--)
	{
		memset(v, -1, sizeof(v));
		int c = 0, ans = -1;
		for (int i = 0; i < 9; i++)
		{
			cin >> ch;
			if (ch == 'H') c |= (1 << i);
		}
		queue<int> q;
		q.push(c);
		v[c] = 0;
		while (!q.empty())
		{
			int now = q.front();
			q.pop();
			if (now == 0 || now == b)
			{
				ans = v[now];
				break;
			}
			for (int i = 0; i < 8; i++)
			{
				int nxt = now;
				for (int j = 0; j < 3; j++)
					nxt = (1 << f[i][j]) ^ nxt;
				if (v[nxt] >= 0) continue;
				v[nxt] = v[now] + 1;
				q.push(nxt);
			}
		}
		cout << ans << '\n';
	}
}

// https://www.acmicpc.net/problem/9079