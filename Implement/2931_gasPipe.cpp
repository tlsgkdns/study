#include <iostream>
#include <vector>
using namespace std;

using p = pair<int, int>;
p src, dst, non = make_pair(-1, -1);
int R, C, g = 1;
vector<vector<char>> pipe;
pair<p, char> ans;
vector<char> shape = { '+','1','2','3','4','|','-' };
int dy[4] = { 0, 0, 1, -1 };
int dx[4] = { 1, -1, 0, 0 };
p getNextPos(char c, p enter)
{
	p ret = non;
	switch (c)
	{
	case '|':
		if (enter == make_pair(1, 0) || enter == make_pair(-1, 0))
			ret = enter;
		break;
	case '-':
		if (enter == make_pair(0, 1) || enter == make_pair(0, -1))
			ret = enter;
		break;
	case '1':
		if (enter == make_pair(0, -1) || enter == make_pair(-1, 0))
			ret = make_pair(-enter.second, -enter.first);
		break;
	case '2':
		if (enter == make_pair(0, -1) || enter == make_pair(1, 0))
			ret = make_pair(enter.second, enter.first);
		break;
	case '3':
		if (enter == make_pair(0, 1) || enter == make_pair(1, 0))
			ret = make_pair(-enter.second, -enter.first);
		break;
	case '4':
		if (enter == make_pair(0, 1) || enter == make_pair(-1, 0))
			ret = make_pair(enter.second, enter.first);
		break;
	case '+':
		ret = enter;
	}
	return ret;
}
p operator+(p p1, p p2)
{
	return make_pair(p1.first + p2.first, p1.second + p2.second);
}
void dfs(p cur, p enter, pair<p, char> added, int gas)
{
	if (enter == non || cur.second < 0 || cur.first < 0 || cur.first >= R || cur.second >= C || gas > g + 1)
		return;
	if (cur == dst && (gas == g || (added.second == '+' && gas == g + 1)))
	{
		ans = added;
		return;
	}
	if (pipe[cur.first][cur.second] == '.')
	{
		if (added.second == '.')
			for (int i = 0; i < shape.size(); i++)
			{
				pipe[cur.first][cur.second] = shape[i];
				dfs(cur + getNextPos(shape[i], enter), getNextPos(shape[i], enter),
					make_pair(make_pair(cur.first, cur.second), shape[i]), gas + 1);
				pipe[cur.first][cur.second] = '.';
			}
		return;
	}
	dfs(cur + getNextPos(pipe[cur.first][cur.second], enter), getNextPos(pipe[cur.first][cur.second], enter), added, gas + 1);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> R >> C;
	pipe.resize(R, vector<char>(C));
	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++)
		{
			cin >> pipe[i][j];
			if (pipe[i][j] == 'M')
				src = make_pair(i, j);
			else if (pipe[i][j] == 'Z')
				dst = make_pair(i, j);
			else if (pipe[i][j] != '.')
				g++;
			if (pipe[i][j] == '+') g++;
		}
	for (int i = 0; i < 4; i++)
	{
		int y = src.first + dy[i];
		int x = src.second + dx[i];
		dfs(make_pair(y, x), make_pair(dy[i], dx[i]), make_pair(make_pair(-1, -1), '.'), 0);
	}
	cout << ans.first.first + 1 << " " << ans.first.second + 1 << " " << ans.second << '\n';
}
// https://www.acmicpc.net/problem/2931