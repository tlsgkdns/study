#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int cauld[5][5], clr[5][5], ingredientVal[10][4][4], ingredientClr[10][4][4];
int N, ans = -1000000000;
char ch;
bool v[11];
int getColor(char ch)
{
	switch (ch)
	{
	case 'R':
		return 1;
	case 'B':
		return 2;
	case 'G':
		return 3;
	case 'Y':
		return 4;
	}
	return 0;
}
void solve(int d)
{
	if (d == 3)
	{
		int score[5] = { 0, 0, 0, 0, 0 };
		for (int i = 0; i < 5; i++)
			for (int j = 0; j < 5; j++)
				score[clr[i][j]] += cauld[i][j];
		int S = score[1] * 7 + score[2] * 5 + score[3] * 3 + score[4] * 2;
		ans = max(S, ans);
		return;
	}
	for (int idx = 0; idx < N; idx++)
	{
		if (v[idx]) continue;
		v[idx] = true;
		int tmpVal[4][4], tmpClr[4][4];
		for (int r = 0; r < 4; r++)
		{
			for (int i = 0; i < 4; i++)
				for (int j = 0; j < 4; j++)
				{
					tmpVal[i][j] = ingredientVal[idx][3 - j][i];
					tmpClr[i][j] = ingredientClr[idx][3 - j][i];
				}
			memcpy(ingredientVal[idx], tmpVal, sizeof(tmpVal));
			memcpy(ingredientClr[idx], tmpClr, sizeof(tmpClr));
			int tmpV[5][5], tmpC[5][5];
			for (int sy = 0; sy <= 1; sy++)
				for (int sx = 0; sx <= 1; sx++)
				{
					memcpy(tmpV, cauld, sizeof(cauld));
					memcpy(tmpC, clr, sizeof(clr));
					for (int y = sy; y < sy + 4; y++)
						for (int x = sx; x < sx + 4; x++)
						{
							cauld[y][x] = min(9, max(0, ingredientVal[idx][y - sy][x - sx] + cauld[y][x]));
							if (ingredientClr[idx][y - sy][x - sx] == 0) continue;
							clr[y][x] = ingredientClr[idx][y - sy][x - sx];
						}
					solve(d + 1);
					memcpy(cauld, tmpV, sizeof(tmpV));
					memcpy(clr, tmpC, sizeof(tmpC));
				}
		}
		v[idx] = false;
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int r = 0; r < 4; r++)
			for (int c = 0; c < 4; c++)
				cin >> ingredientVal[i][r][c];
		for (int r = 0; r < 4; r++)
			for (int c = 0; c < 4; c++)
			{
				cin >> ch;
				ingredientClr[i][r][c] = getColor(ch);
			}
	}
	solve(0);
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/15898