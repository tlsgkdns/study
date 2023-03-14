#include <iostream>
#include <vector>
using namespace std;

vector<pair<int, pair<int, int>>> mv, ansMv;
int arr[4][4], ans = 8;

int calcDismatch()
{
	int ret = 0;
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			ret += (i * 4 + j + 1 != arr[i][j]);
	return ret;
}
void rotateRow(int r)
{
	int tmp = arr[r][0];
	for (int i = 0; i < 3; i++)
		arr[r][i] = arr[r][i + 1];
	arr[r][3] = tmp;
}
void rotateCol(int c)
{
	int tmp = arr[0][c];
	for (int i = 0; i < 3; i++)
		arr[i][c] = arr[i + 1][c];
	arr[3][c] = tmp;
}
void dfs(int d)
{
	int dismatch = calcDismatch();
	if (dismatch == 0)
	{
		if (d < ans)
		{
			ansMv = mv;
			ans = d;
		}
		return;
	}
	if ((dismatch % 4 > 0) + (dismatch / 4) + d >= ans) return;
	for (int r = 0; r < 4; r++)
	{
		for (int k = 1; k <= 3; k++)
		{
			rotateRow(r);
			mv.push_back({ 1, {r + 1, 4 - k} });
			dfs(d + 1);
			mv.pop_back();
		}
		rotateRow(r);
	}
	for (int c = 0; c < 4; c++)
	{
		for (int k = 1; k <= 3; k++)
		{
			rotateCol(c);
			mv.push_back({ 2, {c + 1, 4 - k} });
			dfs(d + 1);
			mv.pop_back();
		}
		rotateCol(c);
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			cin >> arr[i][j];
	dfs(0);
	cout << ans << '\n';
	for (int i = 0; i < ansMv.size(); i++)
		cout << ansMv[i].first << " " << ansMv[i].second.first << " " << ansMv[i].second.second << '\n';
}

// https://www.acmicpc.net/problem/2549