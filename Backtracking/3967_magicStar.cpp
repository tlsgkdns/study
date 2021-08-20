#include <iostream>
#include <vector>
using namespace std;

struct Point
{
	int y = 0;
	int x = 0;
	Point(int ny, int nx)
	{
		y = ny;
		x = nx;
	}
};
vector<vector<char>> star(5, vector<char>(9)), ans;
vector<vector<pair<int, int>>> pos
= { {{0, 4}, {1, 3}, {2, 2}, {3, 1}},
	{{0, 4}, {1, 5}, {2, 6}, {3, 7}},
	{{1, 7}, {2, 6}, {3, 5}, {4, 4}},
	{{1, 1}, {2, 2}, {3, 3}, {4, 4}},
	{{3, 1}, {3, 3}, {3, 5}, {3, 7}},
	{{1, 1}, {1, 3}, {1, 5}, {1, 7}} };
vector<pair<int, int>> xPos;
int ctoi(char c)
{
	return (c - 'A') + 1;
}
bool isValid(vector<vector<char>>& st)
{
	bool ret = true;
	for (int i = 0; i < pos.size(); i++)
	{
		int sum = 0, cnt = 0;
		for (int j = 0; j < pos[0].size(); j++)
		{
			int num = ctoi(st[pos[i][j].first][pos[i][j].second]);
			if (num <= 0 || num >= 13) continue;
			cnt++;
			sum += num;
		}
		if ((cnt == 4 && sum == 26) || (cnt < 4 && sum < 26)) continue;
		ret = false;
	}
	return ret;
}
void solve(vector<bool>& used, int idx)
{
	if (!ans.empty()) return;
	if (idx == xPos.size())
	{
		if (isValid(star))
			ans = star;
		return;
	}
	int y = xPos[idx].first;
	int x = xPos[idx].second;
	for (int i = 1; i <= 12; i++)
	{
		if (used[i] || !isValid(star)) continue;
		star[y][x] = (i - 1) + 'A';
		used[i] = true;
		solve(used, idx + 1);
		star[y][x] = 'x';
		used[i] = false;

	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	vector<bool> used(13, false);
	int cnt = 0; used[0] = true;
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 9; j++)
		{
			cin >> star[i][j];
			if (star[i][j] == 'x') xPos.push_back({ i, j });
			if (star[i][j] == '.' || star[i][j] == 'x') continue;
			cnt++;
			used[ctoi(star[i][j])] = true;
		}
	solve(used, 0);
	for (vector<char> vc : ans)
	{
		for (char c : vc) cout << c;
		cout << '\n';
	}
}
// https://www.acmicpc.net/problem/3967