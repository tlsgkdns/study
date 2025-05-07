#include <iostream>
#include <queue>
using namespace std;
using ll = long long;
ll N, ans = -1, cnt = 0;
queue<ll> q;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i <= 9; i++) q.push(i);
	while (!q.empty())
	{
		ll now = q.front();
		q.pop();
		if (++cnt == N)
		{
			ans = now;
			break;
		}
		int e = now % 10;
		for (int n = 0; n < e; n++)
			q.push(now * 10 + n);
	}
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/1174