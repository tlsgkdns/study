#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<int> col;

int n;

bool isValid(int r)
{
	for (int i = 0; i < r; i++)
	{
		if (col[i] == col[r] || (abs(col[i] - col[r]) == abs(r - i)))
			return false;
	}
	return true;
}
int queen(int row)
{
	if (row == n) return 1;
	int s = 0;
	for (int i = 0; i < n; i++)
	{
		col[row] = i;
		if (isValid(row))
			s += queen(row + 1);
	}

	return s;
}
int main()
{
	cin >> n;
	col.resize(n + 1, 0);

	int ans = queen(0);
	cout << ans << endl;
}
// https://www.acmicpc.net/problem/9663

/*
standard backtracking problem
*/