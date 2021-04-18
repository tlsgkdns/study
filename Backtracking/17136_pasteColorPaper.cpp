#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

const int pLength = 10;
const int cLength = 5;

int ans = 26;

vector<vector<int>> paper(10, vector<int>(10));
vector<int> color{ 5, 5, 5, 5, 5 };

bool canCover(int sy, int sx, int size)
{
	for (int i = sy; i <= sy + size; i++)
		for (int j = sx; j <= sx + size; j++)
			if (paper[i][j] == 0) return false;

	return true;
}

void cover(int sy, int sx, int size, int target)
{
	for (int i = sy; i <= sy + size; i++)
		for (int j = sx; j <= sx + size; j++)
		{
			paper[i][j] = target;
		}

}

void newAnswer(int index, int depth)
{
	if (index == 100)
	{
		ans = min(ans, depth);
		return;
	}

	if (ans <= depth)
		return;
	int i = index / 10, j = index % 10;
	if (paper[i][j] == 0) newAnswer(index + 1, depth);

	for (int c = cLength - 1; c >= 0; c--)
	{
		if (i + c >= 10 || j + c >= 10 || color[c] == 0) continue;
		if (canCover(i, j, c))
		{
			color[c]--;
			cover(i, j, c, 0);
			newAnswer(index + 1, depth + 1);
			color[c]++;
			cover(i, j, c, 1);
		}
	}
}

int main()
{
	for (int i = 0; i < pLength; i++)
		for (int j = 0; j < pLength; j++)
			cin >> paper[i][j];

	vector<vector<bool>> v(10, vector<bool>(10, false));

	newAnswer(0, 0);

	cout << ((ans < 26) ? ans : -1) << '\n';
}

// https://www.acmicpc.net/problem/17136g