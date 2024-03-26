#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int T, N;
string v[20001];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> T;
	while (T--)
	{
		cin >> N;
		queue<int> q;
		for (int i = 0; i < N; i++) v[i] = "";
		if (N == 1)
		{
			cout << 1 << '\n';
			continue;
		}
		v[1] = "1";
		q.push(1);
		while (!q.empty())
		{
			int now = q.front();
			q.pop();
			if (now == 0) break;
			if (v[now].size() > 100) continue;
			int nxt1 = (now * 10) % N;
			int nxt2 = (now * 10 + 1) % N;
			if (v[nxt1].empty())
			{
				v[nxt1] = v[now] + "0";
				q.push(nxt1);
			}
			if (v[nxt2].empty())
			{
				v[nxt2] = v[now] + "1";
				q.push(nxt2);
			}
		}
		if (v[0].empty()) cout << "BRAK\n";
		else cout << v[0] << '\n';
	}
}

// https://www.acmicpc.net/problem/8111