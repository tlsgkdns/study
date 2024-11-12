#include <iostream>
#include <queue>

using namespace std;

int N, A[100001], M, C, I, V;
priority_queue<pair<int, int>> pq;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		cin >> A[i];
		pq.push({ -A[i], -i });
	}
	cin >> M;
	for (int i = 0; i < M; i++)
	{
		cin >> C;
		if (C == 1)
		{
			cin >> I >> V;
			A[I] = V;
			pq.push({ -V, -I });
		}
		else
		{
			while (!pq.empty() && A[-pq.top().second] != -pq.top().first)
				pq.pop();
			cout << -pq.top().second << '\n';
		}
	}
}

// https://www.acmicpc.net/problem/14427