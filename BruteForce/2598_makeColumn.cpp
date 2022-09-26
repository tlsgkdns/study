#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

int side[24][5] = { {0, 1, 2, 3, 4}, {0, 3, 2, 1, 5}, {0, 4, 2, 5, 3}, {0, 5, 2, 4, 1}, {1, 4, 3, 5, 0}, {1, 5, 3, 4, 2},
					{1, 2, 3, 0, 4}, {2, 3, 0, 1, 4}, {3, 0, 1, 2, 4}, {3, 2, 1, 0, 5}, {2, 1, 0, 3, 5}, {1, 0, 3, 2, 5},
					{4, 2, 5, 0, 3}, {2, 5, 0, 4, 3}, {5, 0, 4, 2, 3}, {5, 2, 4, 0, 1}, {2, 4, 0, 5, 1}, {4, 0, 5, 2, 1},
					{4, 3, 5, 1, 0}, {3, 5, 1, 4, 0}, {5, 1, 4, 3, 0}, {5, 3, 4, 1, 2}, {3, 4, 1, 5, 2}, {4, 1, 5, 3, 2} };
int dice[4][6], C, H, ans = 0, color[4];
char ch;
vector<vector<int>> column(4, vector<int>(4));
vector<pair<vector<vector<int>>, int>> columns;

void solve(int idx)
{
	if (idx == 4)
	{
		bool f = true;
		for (int i = 0; i < 4; i++)
			if (color[i] != 15)
			{
				f = false;
				break;
			}
		if (f)
		{
			bool push = true;
			for (int t = 0; t < (int)columns.size(); t++)
			{
				if (H == columns[t].second && columns[t].first == column)
				{
					push = false;
					break;
				}
			}
			if (push)
			{
				for (int d = 0; d < 4; d++)
				{
					vector<vector<int>> tmp(4, vector<int>(4));
					for (int i = 0; i < 4; i++)
						for (int j = 0; j < 4; j++)
							tmp[i][(j + d) % 4] = column[i][j];
					columns.push_back(make_pair(tmp, H));
				}
				ans++;
			}
		}
		return;
	}
	int tmp[4];
	for (int i = 0; i < 24; i++)
	{
		memcpy(tmp, color, sizeof(tmp));
		for (int j = 0; j < 4; j++)
		{
			color[j] |= (1 << dice[idx][side[i][j]]);
			column[idx][j] = dice[idx][side[i][j]];
		}
		if (idx == 3) H = dice[idx][side[i][4]];
		solve(idx + 1);
		memcpy(color, tmp, sizeof(tmp));
	}

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 6; j++)
		{
			cin >> ch;
			switch (ch)
			{
			case 'R':
				C = 0;
				break;
			case 'G':
				C = 1;
				break;
			case 'B':
				C = 2;
				break;
			default:
				C = 3;
			}
			dice[i][j] = C;
		}
	solve(0);
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/2598