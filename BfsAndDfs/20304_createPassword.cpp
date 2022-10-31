#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAX = 2100001;
queue<int> q;
int N, M, P, ans = 0, A = 0;
int v[MAX];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	memset(v, -1, sizeof(v));
	cin >> N >> M;
	while (M--)
	{
		cin >> P;
		q.push(P);
		v[P] = 0;
	}
	while (!q.empty())
	{
		int now = q.front();
		q.pop();
		int idx = 0;
		while (true)
		{
			int nxt = now ^ (1 << (idx++));
			if (nxt >= MAX) break;
			if (v[nxt] >= 0) continue;
			v[nxt] = v[now] + 1;
			if (nxt <= N && ans < v[nxt]) ans = v[nxt];
			q.push(nxt);
		}
	}
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/20304