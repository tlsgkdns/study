#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
using p = pair<int, int>;
const p Dst = make_pair(5, 0);
const p Src = make_pair(0, 0);
vector<vector<int>> adj;
int dice[10];
vector<vector<int>> path;

void init()
{
	path.resize(6);
	for (int i = 0; i < 40; i += 2)
		path[0].push_back(i);
	for (int i = 13; i <= 19; i += 3)
		path[1].push_back(i);
	for (int i = 22; i <= 24; i += 2)
		path[2].push_back(i);
	for (int i = 28; i >= 26; i--)
		path[3].push_back(i);
	for (int i = 25; i <= 40; i += 5)
		path[4].push_back(i);
	path[5].push_back(0);
}
p getNextPath(p pth, int step)
{
	p next = make_pair(pth.first, pth.second + step);

	if (pth.first == 0 && pth.second % 5 == 0 && pth.second != 20 && pth.second != 0)
	{
		next.first = pth.second /= 5;
		next.second = step - 1;
	}
	if (path[next.first].size() - 1 < next.second)
	{
		if (next.first == 1 || next.first == 2 || next.first == 3)
		{
			next.second = next.second - path[next.first].size();
			next.first = 4;
			if (next.second > 3) next = Dst;
		}
		else if (next.first == 0)
		{
			next.second = 3 + next.second - path[next.first].size();
			next.first = 4;
			if (next.second > 3) next = Dst;
		}
		else next = Dst;
	}
	return next;
}
bool sameBoard(p cmp, p a, p b, p c)
{
	return ((cmp == a || cmp == b || cmp == c) && cmp != Dst);
}
int solve(p a, p b, p c, p d, int idx)
{
	int ans = -1;
	if (idx == 10) return 0;
	int step = dice[idx];
	p nxtA = getNextPath(a, step);
	p nxtB = getNextPath(b, step);
	p nxtC = getNextPath(c, step);
	p nxtD = getNextPath(d, step);
	if (!sameBoard(nxtA, b, c, d))
		ans = max(ans, solve(nxtA, b, c, d, idx + 1) + path[nxtA.first][nxtA.second]);
	if (!sameBoard(nxtB, a, c, d))
		ans = max(ans, solve(a, nxtB, c, d, idx + 1) + path[nxtB.first][nxtB.second]);
	if (!sameBoard(nxtC, a, b, d))
		ans = max(ans, solve(a, b, nxtC, d, idx + 1) + path[nxtC.first][nxtC.second]);
	if (!sameBoard(nxtD, a, b, c))
		ans = max(ans, solve(a, b, c, nxtD, idx + 1) + path[nxtD.first][nxtD.second]);
	return ans;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	for (int i = 0; i < 10; i++)
		cin >> dice[i];
	init();
	cout << solve(Src, Src, Src, Src, 0) << '\n';
}

// https://www.acmicpc.net/problem/17825