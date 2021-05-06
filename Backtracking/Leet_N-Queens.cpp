#include <cmath>
#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
	vector<int> col;
	vector<vector<string>> board;
	int l;
	bool isValid(int r)
	{
		for (int i = 0; i < r; i++)
		{
			if (col[i] == col[r] || abs(col[i] - col[r]) == abs(r - i))
				return false;
		}
		return true;
	}
	void queen(int row)
	{
		if (row == l)
		{
			vector<string> b(l, string(l, '.'));
			for (int i = 0; i < l; i++)
			{
				b[col[i]][i] = 'Q';
			}
			board.push_back(b);
			return;
		}
		for (int i = 0; i < l; i++)
		{
			col[row] = i;
			if (isValid(row))
				queen(row + 1);
		}
	}
	vector<vector<string>> solveNQueens(int n) {
		l = n;
		col.resize(n + 1);
		queen(0);
		return board;
	}
};

int main()
{
	int n;
	cin >> n;
	Solution s;
	s.l = n;
	vector<vector<string>> v = s.solveNQueens(n);
	for (vector<string> vs : v)
	{
		for (string s : vs)
			cout << s << '\n';
		cout << '\n';
	}
}

//https://leetcode.com/problems/n-queens/