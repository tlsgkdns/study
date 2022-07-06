#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
using pii = pair<int, int>;
int N, K, t = 0, ans = -1;
int v[500001][2];
int main()
{
	memset(v, -1, sizeof(v));
	cin >> N >> K;
	queue<pii> q;
	q.push({ N, 0 });
	v[N][0] = 0;
	while (!q.empty())
	{
		int here = q.front().first;
		int odd = q.front().second;
		q.pop();
		if (here - 1 > 0 && v[here - 1][!odd] == -1)
		{
			v[here - 1][!odd] = v[here][odd] + 1;
			q.push({ here - 1, !odd });
		}
		if (here + 1 <= 500000 && v[here + 1][!odd] == -1)
		{
			v[here + 1][!odd] = v[here][odd] + 1;
			q.push({ here + 1, !odd });
		}
		if (2 * here <= 500000 && v[2 * here][!odd] == -1)
		{
			v[2 * here][!odd] = v[here][odd] + 1;
			q.push({ 2 * here, !odd });
		}
	}
	while (K <= 500000)
	{
		if (v[K][t % 2] != -1 && v[K][t % 2] <= t)
		{
			ans = t;
			break;
		}
		t++;
		K += t;
	}
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/17071