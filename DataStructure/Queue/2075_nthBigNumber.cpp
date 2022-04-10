#include <iostream>
#include <queue>
using namespace std;
using pii = pair<int, pair<int, int>>;
priority_queue<pii> pq;
int graph[1501][1501];
int N;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{
			cin >> graph[i][j];
			if (i == N - 1)
				pq.push({ graph[i][j], {i, j} });
		}
	for (int i = 0; i < N - 1; i++)
	{
		int idx1 = pq.top().second.first;
		int idx2 = pq.top().second.second;
		pq.pop();
		pq.push({ graph[idx1 - 1][idx2], {idx1 - 1, idx2} });
	}
	cout << pq.top().first << '\n';
}

// https://www.acmicpc.net/problem/2075