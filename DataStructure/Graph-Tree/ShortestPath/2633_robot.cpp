#include <iostream>
#include <cstring>
#include <queue>
#include <deque>
#include <algorithm>
using namespace std;
using pii = pair<int, int>;

vector<pii> tmp;
const int MAX = 205, INF = 1e9;
pii S, D, P1, P2, P3, P4;
int N, ans;
int dy[4] = { 0, -1, 0, 1 };
int dx[4] = { -1, 0, 1, 0 };
bool canMove[MAX][MAX], obs[MAX][MAX];
int v[MAX][MAX][4];
void setLine(pii p1, pii p2)
{
	if (p1.second == p2.second)
		for (int y = min(p1.first, p2.first) + 1; y < max(p1.first, p2.first); y++)
			obs[y][p1.second] = true;
	else if (p1.first == p2.first)
		for (int x = min(p1.second, p2.second) + 1; x < max(p1.second, p2.second); x++)
			obs[p1.first][x] = true;
}
bool inRange(int y, int x)
{
	return y >= 0 && x >= 0 && y < MAX && x < MAX;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> S.second >> S.first; S.second *= 2; S.first *= 2;
	cin >> D.second >> D.first; D.second *= 2; D.first *= 2;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> P1.second >> P1.first;
		cin >> P2.second >> P2.first;
		cin >> P3.second >> P3.first;
		cin >> P4.second >> P4.first;
		P1.second *= 2; P1.first *= 2; P2.second *= 2; P2.first *= 2;
		P3.second *= 2; P3.first *= 2; P4.second *= 2; P4.first *= 2;
		setLine(P1, P2); setLine(P2, P3);
		tmp.push_back(P4);
		pii tmp1, tmp2;
		if (P2.first == P3.first && P1.second == P2.second)
		{
			tmp1 = { P1.first, P4.second };
			tmp2 = { P4.first, P3.second };
		}
		else
		{
			tmp1 = { P4.first, P1.second };
			tmp2 = { P3.first, P4.second };
		}
		setLine(P1, tmp1); setLine(P3, tmp2);
		setLine(tmp1, P4); setLine(P4, tmp2);

	}
	queue<pii> q1;
	canMove[0][0] = true;
	q1.push({ 0, 0 });
	while (!q1.empty())
	{
		int y = q1.front().first;
		int x = q1.front().second;
		q1.pop();
		for (int d = 0; d < 4; d++)
		{
			int ny = dy[d] + y;
			int nx = dx[d] + x;
			if (!inRange(ny, nx) || canMove[ny][nx]) continue;
			canMove[ny][nx] = true;
			if (!obs[ny][nx]) q1.push({ ny, nx });
		}
	}
	for (int i = 0; i < N; i++) canMove[tmp[i].first][tmp[i].second] = true;
	deque<pair<pii, int>> dq;
	memset(v, -1, sizeof(v));
	for (int i = 0; i < 4; i++)
	{
		v[S.first][S.second][i] = 0;
		dq.push_back({ S, i });
	}
	while (!dq.empty())
	{
		int y = dq.front().first.first;
		int x = dq.front().first.second;
		int dir = dq.front().second;
		dq.pop_front();
		if (make_pair(y, x) == D)
		{
			ans = v[y][x][dir];
			break;
		}
		int ny = y + dy[dir], nx = x + dx[dir], nd = dir;
		if (inRange(ny, nx) && (v[ny][nx][nd] < 0 || v[ny][nx][nd] > v[y][x][dir]) && canMove[ny][nx])
		{
			v[ny][nx][nd] = v[y][x][dir];
			dq.push_front({ {ny, nx}, nd });
		}
		nd = (dir + 1) % 4; ny = y + dy[nd]; nx = x + dx[nd];
		if (inRange(ny, nx) && (v[ny][nx][nd] < 0 || v[ny][nx][nd] > v[y][x][dir] + 1) && canMove[ny][nx])
		{
			v[ny][nx][nd] = v[y][x][dir] + 1;
			dq.push_back({ {ny, nx}, nd });
		}
		nd = (dir + 3) % 4; ny = y + dy[nd]; nx = x + dx[nd];
		if (inRange(ny, nx) && (v[ny][nx][nd] < 0 || v[ny][nx][nd] > v[y][x][dir] + 1) && canMove[ny][nx])
		{
			v[ny][nx][nd] = v[y][x][dir] + 1;
			dq.push_back({ {ny, nx}, nd });
		}
	}
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/2633