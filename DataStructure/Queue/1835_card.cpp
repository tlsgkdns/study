#include <iostream>
#include <queue>

using namespace std;

int N, ans[1001];
queue<int> q;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++) q.push(i);
	for (int i = 1; i <= N; i++)
	{
		int s = i;
		while (s--)
		{
			int now = q.front();
			q.push(now);
			q.pop();
		}
		ans[q.front()] = i;
		q.pop();
	}
	for (int i = 0; i < N; i++) cout << ans[i] << " ";
	cout << '\n';
}

// https://www.acmicpc.net/problem/1835