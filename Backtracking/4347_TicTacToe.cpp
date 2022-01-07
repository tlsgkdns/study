#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

vector<bool> ans;
char board[3][3];
int N;
bool a = false;
char getOpp(char c)
{
	if (c == 'X') return 'O';
	return 'X';
}
bool gameEnd(char b[3][3])
{
	for (int i = 0; i < 3; i++)
	{
		if (b[i][0] != '.' && b[i][0] == b[i][1] && b[i][1] == b[i][2])
			return true;
		if (b[0][i] != '.' && b[0][i] == b[1][i] && b[1][i] == b[2][i])
			return true;
	}
	if (b[0][0] != '.' && b[0][0] == b[1][1] && b[1][1] == b[2][2]) return true;
	if (b[0][2] != '.' && b[0][2] == b[1][1] && b[1][1] == b[2][0]) return true;
	return false;
}
void solve(char b[3][3], char turn)
{
	bool s = true;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			if (board[i][j] != b[i][j])
			{
				s = false;
				break;
			}
	if (s)
	{
		a = true;
		return;
	}
	if (gameEnd(b)) return;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
		{
			if (board[i][j] == b[i][j] || board[i][j] != turn) continue;
			b[i][j] = board[i][j];
			solve(b, getOpp(turn));
			b[i][j] = '.';
		}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int r = 0; r < 3; r++)
			for (int c = 0; c < 3; c++)
				cin >> board[r][c];
		a = false;
		char init[3][3];
		memset(init, '.', sizeof(init));
		solve(init, 'X');
		ans.push_back(a);
	}
	for (int an : ans)
		if (an) cout << "yes\n";
		else cout << "no\n";
}

// https://www.acmicpc.net/problem/4347