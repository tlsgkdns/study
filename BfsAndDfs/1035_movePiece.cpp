#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;
char ch;
int dir[4] = { -1, 1, -5, 5 }, cnt = 0, ans = 0;

bool canGo(int here, int d)
{
	if (here % 5 == 0 && d == 0) return false;
	if (here % 5 == 4 && d == 1) return false;
	if (here / 5 == 0 && d == 2) return false;
	if (here / 5 == 4 && d == 3) return false;
	return true;
}
int bfs(int n)
{
	bool v[25] = { false };
	int ret = 0;
	queue<int> q;
	for (int i = 0; i < 25; i++)
	{
		if (n & (1 << i))
		{
			queue<int> q;
			++ret;
			v[i] = true;
			q.push(i);
			while (!q.empty())
			{
				int pos = q.front();
				q.pop();
				for (int d = 0; d < 4; d++)
				{
					if (!canGo(pos, d)) continue;
					int nxtPos = dir[d] + pos;
					if (nxtPos < 0 || nxtPos >= 25 || v[nxtPos] || !(n & (1 << nxtPos))) continue;
					v[nxtPos] = true;
					q.push(nxtPos);
					++ret;
				}
			}
			break;
		}
	}
	return ret;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	unordered_map<int, int> v;
	int s = 0;
	for (int i = 0; i < 25; i++)
	{
		cin >> ch;
		if (ch == '*')
		{
			s |= (1 << i);
			++cnt;
		}
	}
	queue<int> q;
	q.push(s);
	v[s] = 0;
	while (!q.empty())
	{
		int n = q.front();
		q.pop();
		if (bfs(n) == cnt)
		{
			ans = v[n];
			break;
		}
		for (int i = 0; i < 25; i++)
		{
			if (!(n & (1 << i))) continue;
			for (int d = 0; d < 4; d++)
			{
				if (!canGo(i, d)) continue;
				int nxtPos = i + dir[d];
				if (nxtPos < 0 || nxtPos >= 25 || (n & (1 << nxtPos))) continue;
				int tmp = n & (~(1 << i));
				tmp = tmp | (1 << nxtPos);
				if (v.count(tmp) > 0) continue;
				v[tmp] = v[n] + 1;
				q.push(tmp);
			}
		}
	}
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/1035