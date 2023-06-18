#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

const int INF = 1000000007;
int W, H, G, X1, Y1, X2, Y2, T, E, X, Y, dist[902], B[31][31];
int dy[4] = { -1, 1,0 ,0 };
int dx[4] = { 0, 0, -1, 1 };

bool inRange(int y, int x)
{
	return y >= 0 && x >= 0 && y < H && x < W;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	while (true)
	{
		cin >> W >> H;
		if (W == 0 && H == 0) break;
		memset(B, 0, sizeof(B));
		cin >> G; int cnt = W * H - G;
		while (G--)
		{
			cin >> X >> Y;
			B[Y][X] = 1;
		}
		vector<pair<pair<int, int>, int>> edges;
		cin >> E;
		while (E--)
		{
			cin >> X1 >> Y1 >> X2 >> Y2 >> T;
			if (Y1 == H - 1 && X1 == W - 1) continue;
			edges.push_back({ {Y1 * W + X1, Y2 * W + X2}, T });
			B[Y1][X1] = 2;
		}
		for (int i = 0; i < H; i++)
			for (int j = 0; j < W; j++)
			{
				dist[i * W + j] = INF;
				if (B[i][j] > 0 || (i == H - 1 && j == W - 1)) continue;
				for (int d = 0; d < 4; d++)
				{
					int ny = i + dy[d];
					int nx = j + dx[d];
					if (!inRange(ny, nx) || B[ny][nx] == 1) continue;
					edges.push_back({ {i * W + j, ny * W + nx}, 1 });
				}
			}
		dist[0] = 0;
		int dst = (W * H) - 1;
		for (int i = 0; i < cnt - 1; i++)
		{
			for (int idx = 0; idx < edges.size(); idx++)
			{
				int here = edges[idx].first.first;
				int there = edges[idx].first.second;
				int cost = edges[idx].second;
				if (dist[here] == INF || dist[there] <= dist[here] + cost) continue;
				dist[there] = dist[here] + cost;
			}
		}
		bool nev = false;
		for (int idx = 0; idx < edges.size(); idx++)
		{
			int here = edges[idx].first.first;
			int there = edges[idx].first.second;
			int cost = edges[idx].second;
			if (dist[here] == INF) continue;
			if (dist[there] > dist[here] + cost)
			{
				nev = true;
				break;
			}
		}
		if (nev) cout << "Never\n";
		else if (dist[dst] == INF) cout << "Impossible\n";
		else cout << dist[dst] << '\n';
	}
}

// https://www.acmicpc.net/problem/3860