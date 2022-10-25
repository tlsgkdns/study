#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int N, M, B, v[1000001][2];
bool btn[10];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	memset(v, -1, sizeof(v));
	cin >> N;
	cin >> M;
	queue<pair<int, bool>> q;
	for (int i = 0; i < M; i++)
	{
		cin >> B;
		btn[B] = true;
	}
	v[100][1] = 0;
	q.push({ 100, true });
	for (int i = 0; i < 10; i++)
		if (!btn[i])
		{
			v[i][0] = 1;
			q.push({ i, false });
		}
	while (!q.empty())
	{
		int now = q.front().first;
		bool push = q.front().second;
		q.pop();
		if (now == N)
		{
			cout << v[N][push] << '\n';
			break;
		}
		if (push)
		{
			if (now > 0 && v[now - 1][push] < 0)
			{
				v[now - 1][1] = v[now][1] + 1;
				q.push({ now - 1, true });
			}
			if (now < 1000000 && v[now + 1][push] < 0)
			{
				v[now + 1][1] = v[now][1] + 1;
				q.push({ now + 1, true });
			}
		}
		else
		{
			if (v[now][true] < 0)
			{
				v[now][true] = v[now][false];
				q.push({ now, 1 });
			}
			if ((now / 100000) > 0) continue;
			for (int i = 0; i < 10; i++)
			{
				if (btn[i]) continue;
				int nxt = now * 10 + i;
				if (v[nxt][false] < 0)
				{
					v[nxt][0] = v[now][push] + 1;
					q.push({ nxt, false });
				}
			}
		}
	}
}

// https://www.acmicpc.net/problem/1107