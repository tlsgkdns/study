#include <iostream>
#include <cstring>
#include <queue>
#include <cmath>
using namespace std;
using pii = pair<int, int>;
bool dp[21][21][21][21];
vector<pair<pii, pii>> pos;
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };
char farm[20][20];
bool v[20][20];
int N, ans = 0;

bool includeRange(pair<pii, pii> p1, pair<pii, pii> p2)
{
	return (p1.first.first <= p2.first.first) && (p1.first.first <= p2.second.first)
		&& (p1.first.second <= p2.first.second) && (p1.first.second <= p2.second.second)
		&& (p1.second.first >= p2.first.first) && (p1.second.first >= p2.second.first)
		&& (p1.second.second >= p2.first.second) && (p1.second.second >= p2.second.second);
}
int getArea(pair<pii, pii> rec)
{
	return abs(rec.first.first - rec.second.first) * abs(rec.first.second - rec.second.second);
}
bool isPCL(int sr, int er, int sc, int ec)
{
	char c1 = farm[sr][sc], c2 = ' ';
	int cnt1 = 0, cnt2 = 0;
	bool ret = true;
	for (int i = sr; i < er; i++)
	{
		if (!ret) break;
		for (int j = sc; j < ec; j++)
		{
			if (c1 == farm[i][j] || c2 == farm[i][j]) continue;
			if (c2 == ' ') c2 = farm[i][j];
			else
			{
				ret = false;
				break;
			}
		}
	}
	if (c2 == ' ' || !ret) return false;
	queue<pii> q;
	memset(v, false, sizeof(v));
	for (int i = sr; i < er; i++)
		for (int j = sc; j < ec; j++)
		{
			if (v[i][j]) continue;
			if (c1 == farm[i][j]) cnt1++;
			else cnt2++;
			q.push({ i, j });
			v[i][j] = true;
			while (!q.empty())
			{
				int y = q.front().first;
				int x = q.front().second;
				q.pop();
				for (int d = 0; d < 4; d++)
				{
					int ny = y + dy[d];
					int nx = x + dx[d];
					if (ny < sr || ny >= er || nx < sc || nx >= ec
						|| v[ny][nx] || farm[ny][nx] != farm[y][x]) continue;
					v[ny][nx] = true;
					q.push({ ny, nx });
				}
			}
		}
	return (((cnt1 == 1) && (cnt2 >= 2)) || ((cnt1 >= 2) && (cnt2 == 1)));
}
void solve(int sr, int er, int sc, int ec)
{
	if (dp[sr][er][sc][ec]) return;
	if (sr == er || ec == sc) return;
	dp[sr][er][sc][ec] = true;
	if (isPCL(sr, er, sc, ec))
	{
		pos.push_back(make_pair(make_pair(sr, sc), make_pair(er, ec)));
		return;
	}

	solve(sr + 1, er, sc, ec); solve(sr, er - 1, sc, ec);
	solve(sr, er, sc + 1, ec); solve(sr, er, sc, ec - 1);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	memset(dp, false, sizeof(dp));
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> farm[i][j];
	solve(0, N, 0, N);
	vector<bool> used(pos.size(), false);
	ans = pos.size();
	for (int i = 0; i < pos.size(); i++)
		for (int j = i + 1; j < pos.size(); j++)
		{
			if (used[i] || used[j]) continue;
			if (getArea(pos[i]) >= getArea(pos[j]) && includeRange(pos[i], pos[j]))
			{
				used[j] = true;
				ans--;
			}
			else if (getArea(pos[i]) < getArea(pos[j]) && includeRange(pos[j], pos[i]))
			{
				used[i] = true;
				ans--;
			}
		}
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/14529