#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void moveUp(vector<vector<int>>& board)
{
	int n = board.size();
	for (int r = 0; r < n - 1; r++)
	{
		for (int c = 0; c < n; c++)
		{
			int index = r;

			while (index < n && board[index][c] == 0)
				index++;
			if (index < n)
				swap(board[r][c], board[index][c]);
		}
	}
	for (int r = 0; r < n - 1; r++)
	{
		for (int c = 0; c < n; c++)
		{
			if (board[r][c] == board[r + 1][c])
			{
				board[r][c] += board[r + 1][c];
				board[r + 1][c] = 0;
			}
		}
	}
	for (int r = 0; r < n - 1; r++)
	{
		for (int c = 0; c < n; c++)
		{
			int index = r;

			while (index < n && board[index][c] == 0)
				index++;
			if (index < n)
				swap(board[r][c], board[index][c]);
		}
	}

}
void moveDown(vector<vector<int>>& board)
{
	int n = board.size();
	for (int r = n - 1; r > 0; r--)
	{
		for (int c = 0; c < n; c++)
		{
			int index = r;

			while (index >= 0 && board[index][c] == 0)
				index--;
			if (index >= 0)
				swap(board[r][c], board[index][c]);
		}
	}
	for (int r = n - 1; r > 0; r--)
	{
		for (int c = 0; c < n; c++)
		{
			if (board[r][c] == board[r - 1][c])
			{
				board[r][c] += board[r - 1][c];
				board[r - 1][c] = 0;
			}
		}
	}
	for (int r = n - 1; r > 0; r--)
	{
		for (int c = 0; c < n; c++)
		{
			int index = r;

			while (index >= 0 && board[index][c] == 0)
				index--;
			if (index >= 0)
				swap(board[r][c], board[index][c]);
		}
	}
}
void moveLeft(vector<vector<int>>& board)
{
	int n = board.size();
	for (int c = 0; c < n - 1; c++)
	{
		for (int r = 0; r < n; r++)
		{
			int index = c;

			while (index < n && board[r][index] == 0)
				index++;
			if (index < n)
				swap(board[r][c], board[r][index]);
		}
	}

	for (int c = 0; c < n - 1; c++)
	{
		for (int r = 0; r < n; r++)
		{

			if (board[r][c] == board[r][c + 1])
			{
				board[r][c] += board[r][c + 1];
				board[r][c + 1] = 0;
			}
		}
	}
	for (int c = 0; c < n - 1; c++)
	{
		for (int r = 0; r < n; r++)
		{
			int index = c;

			while (index < n && board[r][index] == 0)
				index++;
			if (index < n)
				swap(board[r][c], board[r][index]);
		}
	}
}
void moveRight(vector<vector<int>>& board)
{
	int n = board.size();
	for (int c = n - 1; c > 0; c--)
	{
		for (int r = 0; r < n; r++)
		{
			int index = c;

			while (index >= 0 && board[r][index] == 0)
				index--;
			if (index >= 0)
				swap(board[r][c], board[r][index]);
		}
	}
	for (int c = n - 1; c > 0; c--)
	{
		for (int r = 0; r < n; r++)
		{
			if (board[r][c] == board[r][c - 1])
			{
				board[r][c] += board[r][c - 1];
				board[r][c - 1] = 0;
			}
		}
	}
	for (int c = n - 1; c > 0; c--)
	{
		for (int r = 0; r < n; r++)
		{
			int index = c;

			while (index >= 0 && board[r][index] == 0)
				index--;
			if (index >= 0)
				swap(board[r][c], board[r][index]);
		}
	}
}
int getMax(vector<vector<int>> b)
{
	int m = -1;
	for (vector<int> v : b)
		for (int e : v)
			m = max(e, m);

	return m;
}
int get2048Max(vector<vector<int>> board, int c)
{
	if (c == 5) return getMax(board);
	vector<vector<int>> u = board;
	vector<vector<int>> d = board;
	vector<vector<int>> l = board;
	vector<vector<int>> r = board;

	moveUp(u);
	moveDown(d);
	moveLeft(l);
	moveRight(r);

	int m = max(max(get2048Max(u, c + 1), get2048Max(d, c + 1)), max(get2048Max(l, c + 1), get2048Max(r, c + 1)));

	return m;
}
int main(void)
{
	int n;
	cin >> n;
	vector<vector<int>> board;

	for (int i = 0; i < n; i++)
	{
		vector<int> r;
		for (int j = 0; j < n; j++)
		{
			int e;
			cin >> e;
			r.push_back(e);
		}
		board.push_back(r);
	}

	int answer = get2048Max(board, 0);

	cout << answer << endl;

	return 0;
}

// https://www.acmicpc.net/problem/12100

/*
This problem is not fun.
I hate Bruteforce.
*/