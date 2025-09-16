#include <iostream>
#include <queue>

using namespace std;

priority_queue<int> pq;
int N, M, C, W;

int ans = 1;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		cin >> C;
		pq.push(C);
	}
	for (int i = 0; i < M; i++)
	{
		cin >> W;
		int now = pq.top();
		pq.pop();
		if (now < W)
		{
			ans = 0;
			break;
		}
		else if (now > W)
		{
			pq.push(now - W);
		}
	}
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/23757