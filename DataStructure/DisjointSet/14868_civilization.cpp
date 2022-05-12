#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;

int N, K, X, Y;
int parent[100001], v[2001][2001], sz[100001];
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };
int find(int x)
{
	if (x == parent[x]) return x;
	return parent[x] = find(parent[x]);
}
void merge(int p, int q)
{
	p = find(p); q = find(q);
	if (p < q) swap(p, q);
	if (p == q) return;
	sz[q] += sz[p];
	parent[p] = q;
}
bool inRange(int y, int x)
{
	return y > 0 && x > 0 && y <= N && x <= N;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	queue<pair<int, int>> q;
	memset(v, -1, sizeof(v));
	cin >> N >> K;
	for (int i = 0; i < K; i++)
	{
		parent[i] = i;
		sz[i] = 1;
	}
	for (int i = 0; i < K; i++)
	{
		cin >> Y >> X;
		v[Y][X] = i;
		q.push({ Y, X });
		for (int d = 0; d < 4; d++)
		{
			int NY = Y + dy[d];
			int NX = X + dx[d];
			if (!inRange(NY, NX) || v[NY][NX] == -1 || find(v[NY][NX]) == find(v[Y][X])) continue;
			merge(v[NY][NX], v[Y][X]);
		}
	}
	int ans = 0;
	while (!q.empty() && sz[find(0)] < K)
	{
		int S = (int)q.size();
		ans++;
		for (int s = 0; s < S; s++)
		{
			int y = q.front().first;
			int x = q.front().second;
			q.pop();
			for (int d = 0; d < 4; d++)
			{
				int ny = y + dy[d];
				int nx = x + dx[d];
				if (!inRange(ny, nx)) continue;
				if (v[ny][nx] == -1)
				{
					v[ny][nx] = v[y][x];
					q.push({ ny, nx });
					for (int i = 0; i < 4; i++)
					{
						int nny = ny + dy[i];
						int nnx = nx + dx[i];
						if (!inRange(nny, nnx) || v[nny][nnx] == -1) continue;
						if (find(v[nny][nnx]) != find(v[ny][nx]))
							merge(v[nny][nnx], v[ny][nx]);
					}
				}
				else if (find(v[y][x]) != find(v[ny][nx]))
					merge(v[y][x], v[ny][nx]);
			}
		}
	}
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/14868