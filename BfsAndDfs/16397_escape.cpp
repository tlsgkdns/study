#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int N, T, G;
int v[100001];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	memset(v, -1, sizeof(v));
	queue<int> q;
	cin >> N >> T >> G;
	q.push(N);
	v[N] = 0;
	while (!q.empty())
	{
		int here = q.front();
		q.pop();
		if (here == G) break;
		if (v[here] >= T) continue;
		int there = here + 1;
		if (there < 100000 && v[there] < 0)
		{
			v[there] = v[here] + 1;
			q.push(there);
		}
		there = here * 2;
		if (there < 100000 && there > 0)
		{
			int d = 1;
			while (d <= there) d *= 10;
			d /= 10;
			there -= d;
			if (v[there] < 0)
			{
				v[there] = v[here] + 1;
				q.push(there);
			}
		}
	}
	if (v[G] < 0) cout << "ANG\n";
	else cout << v[G] << '\n';
}

// https://www.acmicpc.net/problem/16397