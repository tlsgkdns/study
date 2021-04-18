#include <iostream>
#include <vector>

using namespace std;
vector<vector<int>> map;
int n, l, ans = 0;

int main()
{
	cin >> n >> l; map.resize(n, vector<int>(n));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> map[i][j];

	for (int i = 0; i < n; i++)
	{
		int floor = map[0][i]; bool slope = false;
		int fl = 1;
		for (int r = 1; r < n; r++)
		{

			if (!slope)
			{
				if (floor == map[r][i] + 1)
				{
					if (l != 1) slope = true;
					floor = map[r][i];
					fl = (l == 1) ? 0 : 1;
				}
				else if (map[r][i] == floor + 1)
				{
					if (fl < l) break;
					else
					{
						floor = map[r][i];
						fl = 1;
					}
				}
				else if (floor == map[r][i])
					fl++;
				else
					break;
			}
			else
			{
				if (floor == map[r][i])
					fl++;
				else if (l != 1 && fl < l) break;
				if (fl == l)
				{
					fl -= l;
					if (floor == map[r][i] + 1)
					{
						floor = map[r][i];
						fl = 1;
					}
					else if (floor + 1 == map[r][i]) break;
					else slope = false;
				}
			}
			if (r == n - 1)
			{
				if (slope && l != 1) continue;
				ans++;
			}
		}
		floor = map[i][0]; slope = false;
		fl = 1;
		for (int c = 1; c < n; c++)
		{
			if (!slope)
			{
				if (floor == map[i][c] + 1)
				{
					if (l != 1) slope = true;
					floor = map[i][c];
					fl = (l == 1) ? 0 : 1;
				}
				else if (map[i][c] == floor + 1)
				{
					if (fl < l) break;
					else
					{
						floor = map[i][c];
						fl = 1;
					}
				}
				else if (floor == map[i][c])
					fl++;
				else
					break;
			}
			else
			{
				if (floor == map[i][c])
					fl++;
				else if (fl < l) break;
				if (fl == l)
				{
					fl -= l;
					if (floor == map[i][c] + 1)
					{
						floor = map[i][c];
						fl = 1;
					}
					else if (floor + 1 == map[i][c]) break;
					else slope = false;
				}
			}
			if (c == n - 1)
			{
				if (slope && l != 1) continue;
				ans++;
			}
		}
	}
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/14890