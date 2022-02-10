#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int MAX = 1002;
int board[MAX][MAX];
int N, X, Y, W, H;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	vector<int> ans(N + 1);
	memset(board, -1, sizeof(board));
	for (int n = 1; n <= N; n++)
	{
		cin >> X >> Y >> W >> H;
		for (int i = X; i < X + W; i++)
			for (int j = Y; j < Y + H; j++)
				board[i][j] = n;
	}
	for (int i = 0; i < MAX; i++)
		for (int j = 0; j < MAX; j++)
			if (board[i][j] != -1)
				ans[board[i][j]]++;
	for (int i = 1; i <= N; i++)
		cout << ans[i] << '\n';
}

// https://www.acmicpc.net/problem/10163