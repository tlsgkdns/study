#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

priority_queue<pair<int, pair<int, int>>> pq;

const int INF = 1000000000;
int room[51][51], v[51][51];
int dy[4] = { 1, 0, -1, 0 };
int dx[4] = { 0, -1, 0, 1 };
int N;
char C;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{
			cin >> C;
			room[i][j] = C - '0';
		}
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			v[i][j] = INF;
	pq.push({ 0, {0, 0} });
	v[0][0] = 0;
	while (!pq.empty())
	{
		int y = pq.top().second.first;
		int x = pq.top().second.second;
		int cost = -pq.top().first;
		pq.pop();
		for (int d = 0; d < 4; d++)
		{
			int ny = y + dy[d];
			int nx = x + dx[d];
			if (ny < 0 || nx < 0 || ny >= N || nx >= N) continue;
			int nc = cost + !(room[ny][nx]);
			if (nc >= v[ny][nx]) continue;
			v[ny][nx] = nc;
			pq.push({ -nc, {ny, nx} });
		}
	}
	cout << v[N - 1][N - 1] << '\n';
}

// https://www.acmicpc.net/problem/2665