#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;
int dst[101], N, M, X, Y, v[101];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	memset(dst, -1, sizeof(dst));
	memset(v, -1, sizeof(v));
	cin >> N >> M;
	for (int i = 0; i < N + M; i++)
	{
		cin >> X >> Y;
		dst[X] = Y;
	}
	queue<int> q;
	q.push(1); v[1] = 0;
	while (!q.empty())
	{
		int here = q.front();
		q.pop();
		if (here == 100) break;
		for (int i = 1; i <= 6; i++)
		{
			int there = min(100, here + i);
			if (v[there] != -1) continue;
			v[there] = v[here] + 1;
			if (dst[there] != -1)
			{
				if (v[dst[there]] != -1) continue;
				v[dst[there]] = v[there];
				there = dst[there];
			}
			q.push(there);
		}
	}
	cout << v[100] << '\n';
}


// https://www.acmicpc.net/problem/16928