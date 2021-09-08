#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };
int dirIdx[4] = { 2, 1, 3, 0 };
int N, M, D, S, ans = 0;
vector<vector<int>> g;
vector<pair<int, int>> moveOrder;
void getMoveOrder()
{
	moveOrder.push_back({ ((N - 1) / 2), ((N - 1) / 2) });
	int dist = 1, idx = 0;
	while (moveOrder.back() != make_pair(0, 0))
	{
		for (int d = 0; d < dist; d++)
		{
			int ny = moveOrder.back().first + dy[dirIdx[idx]];
			int nx = moveOrder.back().second + dx[dirIdx[idx]];
			moveOrder.push_back({ ny, nx });
		}
		if ((idx % 2) == 1) dist = min(N - 1, dist + 1);
		idx = (idx + 1) % 4;
	}
}
void moveMarble()
{
	int tail = 1;
	for (int head = 1; head < moveOrder.size(); head++)
	{
		int hy = moveOrder[head].first;
		int hx = moveOrder[head].second;
		if (g[hy][hx] == 0) continue;
		int ty = moveOrder[tail].first;
		int tx = moveOrder[tail].second;
		tail++;
		if (g[ty][tx] != 0) continue;
		swap(g[ty][tx], g[hy][hx]);
	}
}
void bombMarble()
{
	bool bombed = false;
	do
	{
		int tail = 1;
		bombed = false;
		for (int head = 2; head < moveOrder.size(); head++)
		{
			if (g[moveOrder[tail].first][moveOrder[tail].second]
				== g[moveOrder[head].first][moveOrder[head].second]) continue;
			else if (head - tail >= 4)
				for (int i = tail; i < head; i++)
				{
					ans += g[moveOrder[i].first][moveOrder[i].second];
					g[moveOrder[i].first][moveOrder[i].second] = 0;
					bombed = true;
				}
			tail = head;
		}
		moveMarble();
	} while (bombed);
}
void changeMarble()
{
	vector<vector<int>> tmp(N, vector<int>(N, 0));
	int pushIdx = 1;
	int num = g[moveOrder[1].first][moveOrder[1].second], cnt = 1;
	for (int i = 2; i < moveOrder.size(); i++)
	{
		if (pushIdx >= (N * N)) break;
		if (g[moveOrder[i].first][moveOrder[i].second] != num)
		{
			tmp[moveOrder[pushIdx].first][moveOrder[pushIdx].second] = cnt;
			tmp[moveOrder[pushIdx + 1].first][moveOrder[pushIdx + 1].second] = num;
			num = g[moveOrder[i].first][moveOrder[i].second];
			cnt = 1; pushIdx += 2;
		}
		else
			cnt++;
	}
	g = tmp;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	g.resize(N, vector<int>(N));
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> g[i][j];
	getMoveOrder();
	for (int i = 0; i < M; i++)
	{
		cin >> D >> S;
		for (int s = 1; s <= S; s++)
		{
			int ny = ((N - 1) / 2) + s * dy[D - 1];
			int nx = ((N - 1) / 2) + s * dx[D - 1];
			g[ny][nx] = 0;
		}
		moveMarble();
		bombMarble();
		changeMarble();
	}
	cout << ans << '\n';
}
// https://www.acmicpc.net/problem/21611