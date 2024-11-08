#include <iostream>
#include <vector>

using namespace std;
int T[3][3];
pair<int, int> line[8][3] =
{ {{0, 0}, {1, 1}, {2, 2}},
{{0, 0}, {1, 0}, {2, 0}},
{{1, 0}, {1, 1}, {1, 2}},
{{2, 0}, {2, 1}, {2, 2}},
{{0, 0}, {0, 1}, {0, 2}},
{{0, 1}, {1, 1}, {2, 1}},
{{0, 2}, {1, 2}, {2, 2}},
{{0, 2}, {1, 1}, {2, 0}}
};
bool checkWin(int player)
{
	for (int i = 0; i < 8; i++)
	{
		bool w = true;
		for (int j = 0; j < 3; j++)
			if (T[line[i][j].first][line[i][j].second] != player)
			{
				w = false;
				break;
			}
		if (w)
			return true;
	}
	return false;
}
int opp(int p)
{
	if (p == 1) return 2;
	return 1;
}
int solve(int player)
{
	bool f = false;
	for (int i = 0; i < 3 && !f; i++)
		for (int j = 0; j < 3; j++)
		{
			if (T[i][j] == 0)
			{
				f = true;
				break;
			}
		}
	if (!f) return 0;
	int ret = opp(player);
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			if (T[i][j] == 0)
			{
				T[i][j] = player;
				if (checkWin(player))
				{
					T[i][j] = 0;
					return player;
				}
				int tmp = solve(opp(player));
				if (tmp == player)
				{
					T[i][j] = 0;
					return player;
				}
				else if (tmp == 0) ret = 0;
				T[i][j] = 0;
			}
	return ret;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int a1 = 0, a2 = 0;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
		{
			cin >> T[i][j];
			a1 += (T[i][j] == 1);
			a2 += (T[i][j] == 2);
		}
	int p = (a1 == a2) ? 1 : 2;
	int ans = 0;
	ans = solve(p);
	if (p == ans) cout << "W\n";
	else if (ans == 0) cout << "D\n";
	else cout << "L\n";
}

// https://www.acmicpc.net/problem/16571