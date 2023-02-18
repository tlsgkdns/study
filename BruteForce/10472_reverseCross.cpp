#include <iostream>
#include <queue>
#include <unordered_map>
#include <cstring>
using namespace std;
int P, v[520];
int dy[5] = { 0, -1, 1, 0, 0 };
int dx[5] = { 0, 0, 0, -1, 1 };
bool inRange(int y, int x)
{
	return y >= 0 && x >= 0 && y < 3 && x < 3;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> P;
	while (P--)
	{
		queue<int> q;
		memset(v, -1, sizeof(v));
		char ch = ' '; int ans = 0, num = 0;
		for (int i = 0; i < 9; i++)
		{
			cin >> ch;
			if (ch == '*') num |= (1 << i);
		}
		v[num] = 0;
		q.push(num);
		while (!q.empty())
		{
			int here = q.front();
			q.pop();
			if (here == 0)
			{
				ans = v[here];
				break;
			}
			for (int r = 0; r < 3; r++)
				for (int c = 0; c < 3; c++)
				{
					int there = here;
					for (int d = 0; d < 5; d++)
					{
						int nr = r + dy[d];
						int nc = c + dx[d];
						if (!inRange(nr, nc)) continue;
						there ^= (1 << (nr * 3 + nc));
					}
					if (v[there] >= 0) continue;
					v[there] = v[here] + 1;
					q.push(there);
				}
		}
		cout << ans << '\n';
	}
}

// https://www.acmicpc.net/problem/10472