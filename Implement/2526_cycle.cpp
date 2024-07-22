#include <iostream>
#include <cstring>
using namespace std;

int N, P, cnt = 0, now = 0, v[1001], ans = 0;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> P;
	memset(v, -1, sizeof(v));
	now = N;
	v[N] = 0;
	while (true)
	{
		int nxt = (now * N) % P;
		if (v[nxt] >= 0)
		{
			ans = v[now] - v[nxt] + 1;
			break;
		}
		v[nxt] = ++cnt;
		now = nxt;
	}
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/2526