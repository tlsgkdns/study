#include <iostream>
#include <queue>

using namespace std;

queue<int> q;
int N, M, A, ans = 0;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
		q.push(i);
	for (int i = 0; i < M; i++)
	{
		cin >> A;
		int cnt = 0;
		while (true)
		{
			int f = q.front();
			q.pop();
			if (f == A) break;
			++cnt;
			q.push(f);
		}
		if (cnt > q.size() / 2) cnt = q.size() - cnt + 1;
		ans += cnt;
	}
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/1021