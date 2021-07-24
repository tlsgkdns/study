#include <iostream>
#include <vector>
using namespace std;

int N, t, x, y, blk = 0, score = 0;
const int greenRow = 6, greenCol = 4, blueRow = 4, blueCol = 6;

vector<vector<bool>> blue(blueRow, vector<bool>(blueCol, false)),
green(greenRow, vector<bool>(greenCol, false));

void deleteLastBlue(int t)
{
	if (t == 0) return;
	vector<vector<bool>> tmp(blueRow, vector<bool>(blueCol, false));
	for (int i = 0; i < blueRow; i++)
		for (int j = blueCol - t; j < blueCol; j++)
			if (blue[i][j]) blk--;
	for (int r = 0; r < blueRow; r++)
		for (int c = 0; c < blueCol - t; c++)
			tmp[r][c + t] = blue[r][c];
	blue = tmp;
}
void deleteLastGreen(int t)
{
	if (t == 0) return;
	vector<vector<bool>> tmp(greenRow, vector<bool>(greenCol, false));
	for (int i = greenRow - t; i < greenRow; i++)
		for (int j = 0; j < greenCol; j++)
			if (green[i][j]) blk--;

	for (int r = 0; r < greenRow - t; r++)
		for (int c = 0; c < greenCol; c++)
			tmp[r + t][c] = green[r][c];
	green = tmp;
}
void insertBlue(vector<pair<int, int>> block)
{
	vector<vector<bool>> tmp(blueRow, vector<bool>(blueCol + 4, false));
	for (int c = 0; c < blueCol; c++)
		for (int r = 0; r < blueRow; r++)
			tmp[r][c + 4] = blue[r][c];
	while (true)
	{
		bool f = false;
		for (int i = 0; i < block.size(); i++)
			if (block[i].second >= blueCol + 3 || tmp[block[i].first][block[i].second + 1])
				f = true;
		if (f) break;
		for (int i = 0; i < block.size(); i++)
			block[i].second++;

	}

	for (int i = 0; i < block.size(); i++)
	{
		blk++;
		tmp[block[i].first][block[i].second] = true;
	}

	for (int i = 0; i < tmp.size(); i++)
		for (int j = 4; j < tmp[0].size(); j++)
			blue[i][j - 4] = tmp[i][j];
}
void insertGreen(vector<pair<int, int>> block)
{
	vector<vector<bool>> tmp(greenRow + 4, vector<bool>(greenCol, false));
	for (int r = 0; r < greenRow; r++)
		for (int c = 0; c < greenCol; c++)
			tmp[r + 4][c] = green[r][c];
	while (true)
	{
		bool f = false;
		for (int i = 0; i < block.size(); i++)
			if (block[i].first >= greenRow + 3 || tmp[block[i].first + 1][block[i].second])
				f = true;
		if (f) break;
		for (int i = 0; i < block.size(); i++)
			block[i].first++;
	}

	for (int i = 0; i < block.size(); i++)
	{
		blk++;
		tmp[block[i].first][block[i].second] = true;
	}

	for (int i = 4; i < tmp.size(); i++)
		for (int j = 0; j < tmp[0].size(); j++)
			green[i - 4][j] = tmp[i][j];
}

void popBlue()
{
	vector<vector<bool>> tmp(blueRow, vector<bool>(blueCol, false));
	int idx = blueCol - 1;
	for (int c = blueCol - 1; c >= 0; c--)
	{
		bool f = false;
		for (int r = 0; r < blueRow; r++)
			if (!blue[r][c])
			{
				f = true;
				break;
			}
		if (!f)
		{
			blk -= blueRow;
			score++;
			continue;
		}
		for (int r = 0; r < blueRow; r++)
			tmp[r][idx] = blue[r][c];
		idx--;
	}
	blue = tmp;
}
void popGreen()
{
	vector<vector<bool>> tmp(greenRow, vector<bool>(greenCol, false));
	int idx = greenRow - 1;
	for (int r = greenRow - 1; r >= 0; r--)
	{
		bool f = false;
		for (int c = 0; c < greenCol; c++)
			if (!green[r][c])
			{
				f = true;
				break;
			}
		if (!f)
		{
			blk -= greenCol;
			score++;
			continue;
		}
		for (int c = 0; c < greenCol; c++)
			tmp[idx][c] = green[r][c];
		idx--;
	}
	green = tmp;
}
int getDeleteBlueNum()
{
	int ret = 0;
	for (int c = 1; c >= 0; c--)
	{
		bool f = false;
		for (int r = 0; r < blueRow; r++)
			if (blue[r][c])
			{
				f = true;
				break;
			}
		if (!f) break;
		ret++;
	}
	return ret;
}
int getDeleteGreenNum()
{
	int ret = 0;
	for (int r = 1; r >= 0; r--)
	{
		bool f = false;
		for (int c = 0; c < blueRow; c++)
			if (green[r][c])
			{
				f = true;
				break;
			}
		if (!f) break;
		ret++;
	}
	return ret;
}
vector<pair<int, int>> setBlock()
{
	vector<pair<int, int>> block;
	switch (t)
	{
	case 2:
		block.push_back(make_pair(x, y + 1));
		break;
	case 3:
		block.push_back(make_pair(x + 1, y));
		break;
	}
	block.push_back(make_pair(x, y));
	return block;
}
void run()
{
	vector<pair<int, int>> block = setBlock();
	insertBlue(block);
	insertGreen(block);
	popBlue();
	popGreen();
	deleteLastBlue(getDeleteBlueNum());
	deleteLastGreen(getDeleteGreenNum());
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> t >> x >> y;
		blue; green;
		run();
	}
	blue; green;
	cout << score << '\n' << blk << '\n';
}
// https://www.acmicpc.net/problem/20061