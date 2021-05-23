#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
struct Cube
{
	char up[3][3] = {}, down[3][3] = {}, back[3][3] = {},
		front[3][3] = {}, left[3][3] = {}, right[3][3] = {};
	Cube()
	{
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
			{
				up[i][j] = 'w'; down[i][j] = 'y'; back[i][j] = 'o';
				front[i][j] = 'r'; left[i][j] = 'g'; right[i][j] = 'b';
			}
	}
	pair<int, int> clockwiseIdx(int a, int b)
	{
		return make_pair(2 - b, a);
	}
	void rotateUpClockWise()
	{
		char tmp[3] = { back[0][0], back[0][1], back[0][2] };
		for (int i = 0; i < 3; i++) back[0][i] = left[0][i];
		for (int i = 0; i < 3; i++) left[0][i] = front[0][i];
		for (int i = 0; i < 3; i++) front[0][i] = right[0][i];
		for (int i = 0; i < 3; i++) right[0][i] = tmp[i];
		char rotated[3][3];
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
			{
				pair<int, int> p = clockwiseIdx(i, j);
				rotated[i][j] = up[p.first][p.second];
			}

		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
				up[i][j] = rotated[i][j];
	}
	void rotateUpCounterClockWise()
	{
		for (int i = 0; i < 3; i++)
			rotateUpClockWise();
	}
	void rotateDownClockWise()
	{
		char tmp[3] = { back[2][0], back[2][1], back[2][2] };
		for (int i = 0; i < 3; i++) back[2][i] = right[2][i];
		for (int i = 0; i < 3; i++) right[2][i] = front[2][i];
		for (int i = 0; i < 3; i++) front[2][i] = left[2][i];
		for (int i = 0; i < 3; i++) left[2][i] = tmp[i];
		char rotated[3][3];
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
			{
				pair<int, int> p = clockwiseIdx(i, j);
				rotated[i][j] = down[p.first][p.second];
			}
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
				down[i][j] = rotated[i][j];
	}
	void rotateDownCounterClockWise()
	{
		for (int i = 0; i < 3; i++)
			rotateDownClockWise();
	}
	void rotateLeftClockWise()
	{
		char tmp[3] = { up[0][0], up[1][0], up[2][0] };

		for (int i = 0; i < 3; i++) up[i][0] = back[2 - i][2];
		for (int i = 0; i < 3; i++) back[i][2] = down[2 - i][0];
		for (int i = 0; i < 3; i++) down[i][0] = front[i][0];
		for (int i = 0; i < 3; i++) front[i][0] = tmp[i];
		char rotated[3][3];
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
			{
				pair<int, int> p = clockwiseIdx(i, j);
				rotated[i][j] = left[p.first][p.second];
			}
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
				left[i][j] = rotated[i][j];
	}
	void rotateLeftCounterClockWise()
	{
		for (int i = 0; i < 3; i++)
			rotateLeftClockWise();
	}
	void rotateRightClockWise()
	{
		char tmp[3] = { up[0][2], up[1][2], up[2][2] };
		for (int i = 0; i < 3; i++) up[i][2] = front[i][2];
		for (int i = 0; i < 3; i++) front[i][2] = down[i][2];
		for (int i = 0; i < 3; i++) down[i][2] = back[2 - i][0];
		for (int i = 0; i < 3; i++) back[i][0] = tmp[2 - i];
		char rotated[3][3];
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
			{
				pair<int, int> p = clockwiseIdx(i, j);
				rotated[i][j] = right[p.first][p.second];
			}
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
				right[i][j] = rotated[i][j];
	}
	void rotateRightCounterClockWise()
	{
		for (int i = 0; i < 3; i++)
			rotateRightClockWise();
	}
	void rotateFrontClockWise()
	{
		char tmp[3] = { up[2][0], up[2][1], up[2][2] };

		for (int i = 0; i < 3; i++) up[2][i] = left[2 - i][2];
		for (int i = 0; i < 3; i++) left[i][2] = down[0][i];
		for (int i = 0; i < 3; i++) down[0][i] = right[2 - i][0];
		for (int i = 0; i < 3; i++) right[i][0] = tmp[i];

		char rotated[3][3];
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
			{
				pair<int, int> p = clockwiseIdx(i, j);
				rotated[i][j] = front[p.first][p.second];
			}
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
				front[i][j] = rotated[i][j];
	}
	void rotateFrontCounterClockWise()
	{
		for (int i = 0; i < 3; i++)
			rotateFrontClockWise();
	}
	void rotateBackClockWise()
	{
		char tmp[3] = { up[0][0], up[0][1], up[0][2] };
		for (int i = 0; i < 3; i++) up[0][i] = right[i][2];
		for (int i = 0; i < 3; i++) right[i][2] = down[2][2 - i];
		for (int i = 0; i < 3; i++) down[2][i] = left[i][0];
		for (int i = 0; i < 3; i++) left[i][0] = tmp[2 - i];
		char rotated[3][3];
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
			{
				pair<int, int> p = clockwiseIdx(i, j);
				rotated[i][j] = back[p.first][p.second];
			}
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
				back[i][j] = rotated[i][j];
	}
	void rotateBackCounterClockWise()
	{
		for (int i = 0; i < 3; i++)
			rotateBackClockWise();
	}
};

int main()
{
	int t, n;
	cin >> t;
	vector<Cube> ans;
	for (int idx = 0; idx < t; idx++)
	{
		Cube cube;
		string cmd;
		cin >> n;
		for (int c = 0; c < n; c++)
		{
			cin >> cmd;
			switch (cmd[0])
			{
			case 'F':
				if (cmd[1] == '+')
					cube.rotateFrontClockWise();
				else
					cube.rotateFrontCounterClockWise();
				break;
			case 'L':
				if (cmd[1] == '+')
					cube.rotateLeftClockWise();
				else
					cube.rotateLeftCounterClockWise();
				break;
			case 'B':
				if (cmd[1] == '+')
					cube.rotateBackClockWise();
				else
					cube.rotateBackCounterClockWise();
				break;
			case 'U':
				if (cmd[1] == '+')
					cube.rotateUpClockWise();
				else
					cube.rotateUpCounterClockWise();
				break;
			case 'D':
				if (cmd[1] == '+')
					cube.rotateDownClockWise();
				else
					cube.rotateDownCounterClockWise();
				break;
			case 'R':
				if (cmd[1] == '+')
					cube.rotateRightClockWise();
				else
					cube.rotateRightCounterClockWise();
				break;
			}
		}
		ans.push_back(cube);
	}
	for (int idx = 0; idx < ans.size(); idx++)
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
				cout << ans[idx].up[i][j];
			cout << '\n';
		}
}

//https://www.acmicpc.net/problem/5373