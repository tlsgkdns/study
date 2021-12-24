#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

const int INF = 1000000000;

pair<int, int> fl = { 3, -3 }, fr = { 4, -3 }, rl = { 3, -4 }, rr = { 4, -4 },
yln = { 0, INF }, xln = { INF, 0 }, yl = { 0, -INF }, xl = { -INF, 0 };

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };
int head = 0, rit = 1, rear = 2, lft = 3, N, ans = 0;
string cmd;

int getDist(pair<int, int>& p1, pair<int, int>& p2)
{
	return max(abs(p1.first - p2.first), abs(p1.second - p2.second));
}
bool equalCell()
{
	return (fl == fr) || (rl == rr) || (fl == rl)
		|| (fl == rr) || (rl == fr) || (fr == rr);
}
pair<int, int> getRot(pair<int, int>& rot, pair<int, int>& pivot)
{
	pair<int, int> tmp = make_pair(rot.first - pivot.first, rot.second - pivot.second);
	tmp = make_pair(tmp.second, -tmp.first);
	tmp = make_pair(tmp.first + pivot.first, tmp.second + pivot.second);
	return tmp;
}

void setEndPos(pair<int, int> p)
{
	if (yln.second > p.second) yln = p;
	if (xln.first > p.first) xln = p;
	if (yl.second < p.second) yl = p;
	if (xl.first < p.first) xl = p;
}
void setAnswer()
{
	if (ans == -1) return;
	setEndPos(fl); setEndPos(fr);
	setEndPos(rr); setEndPos(rl);
	ans = max(ans, ((abs(yln.second - yl.second) + 1) *
		(abs(xln.first - xl.first) + 1)));
}
void moveFoot(pair<int, int>& foot, int dir)
{
	foot = make_pair(foot.first + dx[dir], foot.second + dy[dir]);
	if (equalCell()) ans = -1;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> cmd;
		string str(cmd.begin(), cmd.begin() + 2);
		if (cmd[2] == 'P')
		{
			head = (head + 1) % 4;
			rit = (rit + 1) % 4;
			lft = (lft + 1) % 4;
			rear = (rear + 1) % 4;
			pair<int, int> pivot;
			bool frf = false, flf = false, rlf = false, rrf = false;
			if (str == "FR")
			{
				frf = true;
				pivot = fr;
			}
			if (str == "FL")
			{
				flf = true;
				pivot = fl;
			}
			if (str == "RL")
			{
				rlf = true;
				pivot = rl;
			}
			if (str == "RR")
			{
				rrf = true;
				pivot = rr;
			}
			if (!frf) fr = getRot(fr, pivot);
			if (!flf) fl = getRot(fl, pivot);
			if (!rlf) rl = getRot(rl, pivot);
			if (!rrf) rr = getRot(rr, pivot);
			if (equalCell()) ans = -1;
		}
		if (cmd[2] == 'F')
		{
			if (str == "FR") moveFoot(fr, head);
			if (str == "FL") moveFoot(fl, head);
			if (str == "RL") moveFoot(rl, head);
			if (str == "RR") moveFoot(rr, head);
		}
		if (cmd[2] == 'R')
		{
			if (str == "FR") moveFoot(fr, rit);
			if (str == "FL") moveFoot(fl, rit);
			if (str == "RL") moveFoot(rl, rit);
			if (str == "RR") moveFoot(rr, rit);
		}
		if (cmd[2] == 'L')
		{
			if (str == "FR") moveFoot(fr, lft);
			if (str == "FL") moveFoot(fl, lft);
			if (str == "RL") moveFoot(rl, lft);
			if (str == "RR") moveFoot(rr, lft);
		}
		if (cmd[2] == 'B')
		{
			if (str == "FR") moveFoot(fr, rear);
			if (str == "FL") moveFoot(fl, rear);
			if (str == "RL") moveFoot(rl, rear);
			if (str == "RR") moveFoot(rr, rear);
		}
		setAnswer();
	}
	if (ans == -1) cout << ans << '\n';
	else cout << ans << '\n';
}

// https://www.acmicpc.net/problem/5830