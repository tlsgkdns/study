#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int N, T, X, Y, score = 0;
int blue[4][6], green[6][4];
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };

void deleteRight()
{
	int tmp[4][6];
	memset(tmp, -1, sizeof(tmp));
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 5; j++)
			tmp[i][j + 1] = blue[i][j];
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 6; j++)
			blue[i][j] = tmp[i][j];
}
void deleteDown()
{
	int tmp[6][4];
	memset(tmp, -1, sizeof(tmp));
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 4; j++)
			tmp[i + 1][j] = green[i][j];
	for (int i = 0; i < 6; i++)
		for (int j = 0; j < 4; j++)
			green[i][j] = tmp[i][j];
}
void blueBlockDown()
{
	while (true)
	{
		bool br = true;
		for (int i = 4; i >= 0; i--)
		{
			for (int j = 0; j < 4; j++)
				if (blue[j][i] >= 0 && blue[j][i + 1] < 0)
				{
					if ((j < 3 && blue[j + 1][i] == blue[j][i]))
					{
						if (blue[j + 1][i + 1] < 0)
						{
							blue[j][i + 1] = blue[j][i];
							blue[j + 1][i + 1] = blue[j][i];
							blue[j][i] = -1;
							blue[j + 1][i] = -1;
							br = false;
						}
					}
					else if (j > 0 && blue[j - 1][i] == blue[j][i])
					{
						if (blue[j - 1][i + 1] < 0)
						{
							blue[j][i + 1] = blue[j][i];
							blue[j - 1][i + 1] = blue[j][i];
							blue[j][i] = -1;
							blue[j - 1][i] = -1;
							br = false;
						}
					}
					else
					{
						blue[j][i + 1] = blue[j][i];
						blue[j][i] = -1;
						br = false;
					}
				}
		}
		if (br) break;
	}

}
void greenBlockDown()
{
	while (true)
	{
		bool br = true;
		for (int i = 4; i >= 0; i--)
		{
			int s = -1;
			for (int j = 0; j < 4; j++)
				if (green[i][j] >= 0 && green[i + 1][j] < 0)
				{
					if ((j < 3 && green[i][j + 1] == green[i][j]))
					{
						if (green[i + 1][j + 1] < 0)
						{
							green[i + 1][j] = green[i][j];
							green[i + 1][j + 1] = green[i][j];
							green[i][j] = -1;
							green[i][j + 1] = -1;
							br = false;
						}
					}
					else if (j > 0 && green[i][j - 1] == green[i][j])
					{
						if (green[i + 1][j - 1] < 0)
						{
							green[i + 1][j] = green[i][j];
							green[i + 1][j - 1] = green[i][j];
							green[i][j] = -1;
							green[i][j - 1] = -1;
							br = false;
						}
					}
					else
					{
						green[i + 1][j] = green[i][j];
						green[i][j] = -1;
						br = false;
					}
				}
		}
		if (br) break;
	}
}
bool bombBlue()
{
	bool ret = false;
	for (int i = 0; i < 6; i++)
	{
		bool f = true;
		for (int j = 0; j < 4; j++)
			if (blue[j][i] < 0)
				f = false;
		if (f)
		{
			for (int j = 0; j < 4; j++)
				blue[j][i] = -1;
			ret = true;
			++score;
		}
	}
	return ret;
}
bool bombGreen()
{
	bool ret = false;
	for (int i = 0; i < 6; i++)
	{
		bool f = true;
		for (int j = 0; j < 4; j++)
			if (green[i][j] < 0)
				f = false;
		if (f)
		{
			for (int j = 0; j < 4; j++)
				green[i][j] = -1;
			ret = true;
			++score;
		}
	}
	return ret;
}
void dropBlockBlue(int t, int y, int x, int n)
{
	int ty = y, tx = 0;
	blue[ty][tx] = n;
	if (t == 3) blue[ty + 1][tx] = n;
	if (t == 2) blue[ty][tx + 1] = n;
	while (true)
	{
		if (tx == 5) break;
		if (t == 1)
		{
			if (blue[ty][tx + 1] >= 0) break;
			blue[ty][tx] = -1;
			++tx;
			blue[ty][tx] = n;
		}
		if (t == 2)
		{
			if (tx == 4 || blue[ty][tx + 2] >= 0) break;
			blue[ty][tx] = -1;
			blue[ty][tx + 2] = n;
			++tx;
		}
		if (t == 3)
		{
			if (blue[ty + 1][tx + 1] >= 0 || blue[ty][tx + 1] >= 0) break;
			blue[ty][tx] = -1;
			blue[ty + 1][tx] = -1;
			blue[ty][tx + 1] = n;
			blue[ty + 1][tx + 1] = n;
			++tx;
		}
	}
}
void dropBlockGreen(int t, int y, int x, int n)
{
	int ty = 0, tx = x;
	green[ty][tx] = n;
	if (t == 3) green[ty + 1][tx] = n;
	if (t == 2) green[ty][tx + 1] = n;
	while (true)
	{
		if (ty == 5) break;
		if (t == 1)
		{
			if (green[ty + 1][tx] >= 0) break;
			green[ty][tx] = -1;
			++ty;
			green[ty][tx] = n;
		}
		if (t == 3)
		{
			if (ty == 4 || green[ty + 2][tx] >= 0) break;
			green[ty][tx] = -1;
			green[ty + 2][tx] = n;
			++ty;
		}
		if (t == 2)
		{
			if (green[ty + 1][tx + 1] >= 0 || green[ty + 1][tx] >= 0) break;
			green[ty][tx] = -1;
			green[ty][tx + 1] = -1;
			green[ty + 1][tx] = n;
			green[ty + 1][tx + 1] = n;
			++ty;
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	memset(green, -1, sizeof(green));
	memset(blue, -1, sizeof(blue));
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> T >> X >> Y;
		dropBlockBlue(T, X, Y, i);
		dropBlockGreen(T, X, Y, i);
		while (bombBlue()) blueBlockDown();
		while (bombGreen()) greenBlockDown();
		for (int i = 0; i < 2; i++)
			for (int j = 0; j < 4; j++)
				if (blue[j][1] >= 0)
				{
					deleteRight();
					break;
				}
		for (int i = 0; i < 2; i++)
			for (int j = 0; j < 4; j++)
				if (green[1][j] >= 0)
				{
					deleteDown();
					break;
				}
	}
	int b = 0;
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 6; j++)
			b += (blue[i][j] >= 0) + (green[j][i] >= 0);
	cout << score << '\n' << b << '\n';
}

// https://www.acmicpc.net/problem/19235