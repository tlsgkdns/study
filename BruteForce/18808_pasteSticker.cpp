#include <iostream>
#include <vector>
using namespace std;

vector<vector<vector<int>>> sticker;
vector<vector<int>> board;
int N, M, K, R, C;

void rotateSticker(int idx)
{
	int r = sticker[idx].size();
	int c = sticker[idx][0].size();
	vector<vector<int>> tmp(c, vector<int>(r));
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			tmp[j][r - 1 - i] = sticker[idx][i][j];
	sticker[idx] = tmp;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M >> K;
	board.resize(N, vector<int>(M, 0));
	for (int i = 0; i < K; i++)
	{
		cin >> R >> C;
		vector<vector<int>> tmp(R, vector<int>(C));
		for (int i = 0; i < R; i++)
			for (int j = 0; j < C; j++)
				cin >> tmp[i][j];
		sticker.push_back(tmp);
	}
	int idx = 0, rot = 0;
	while (idx < K)
	{
		int r = sticker[idx].size();
		int c = sticker[idx][0].size();
		bool sticked = false;
		for (int sr = 0; sr < N - r + 1; sr++)
		{
			if (sticked) break;
			for (int sc = 0; sc < M - c + 1; sc++)
			{
				if (sticked) break;
				bool canStick = true;
				for (int i = 0; i < r; i++)
				{
					if (!canStick) break;
					for (int j = 0; j < c; j++)
					{
						if (board[i + sr][j + sc] == 1 && sticker[idx][i][j] == 1)
						{
							canStick = false;
							break;
						}
					}
				}
				if (canStick)
				{
					for (int i = 0; i < r; i++)
						for (int j = 0; j < c; j++)
							if (board[i + sr][j + sc] == 0 && sticker[idx][i][j] == 1)
								board[i + sr][j + sc] = 1;
					sticked = true;
				}
			}
		}
		if (sticked || rot == 3)
		{
			rot = 0;
			idx++;
		}
		else
		{
			rot++;
			rotateSticker(idx);
		}
	}
	int ans = 0;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			if (board[i][j]) ans++;
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/18808