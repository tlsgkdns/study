#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> sudo(9, vector<int>(9));
bool once = false;
bool isValid(int r, int c, int num)
{
	for (int i = 0; i < 9; i++)
	{
		if (sudo[r][i] == num) return false;
		if (sudo[i][c] == num) return false;
	}

	for (int i = ((r / 3) * 3); i < (((r / 3) + 1) * 3); i++)
		for (int j = ((c / 3) * 3); j < (((c / 3) + 1) * 3); j++)
			if (sudo[i][j] == num) return false;


	return true;
}
void printS()
{
	for (vector<int> s : sudo)
	{
		for (int e : s) cout << e << " ";
		cout << '\n';
	}
	cout << '\n';
	once = true;
}

void fill(int r, int c)
{
	if (r == 9) { printS(); return; }
	if (once) return;
	if (sudo[r][c] != 0)
	{
		if (c == 8) fill(r + 1, 0);
		else fill(r, c + 1);
		return;
	}

	for (int n = 1; n < 10; n++)
	{
		if (isValid(r, c, n))
		{
			sudo[r][c] = n;
			if (c == 8) fill(r + 1, 0);
			else fill(r, c + 1);
			if (once) return;
			sudo[r][c] = 0;
		}
	}
}

int main()
{
	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++)
			cin >> sudo[i][j];

	fill(0, 0);
}

// https://www.acmicpc.net/problem/2580

/*
it was bothersome to calculate diagonal position.
*/