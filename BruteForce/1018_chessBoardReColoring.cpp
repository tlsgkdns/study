#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;

int reColor(vector<vector<bool>>& rec)
{
	bool b = false;
	int r1 = 0, r2 = 0;
	for (int i = 0; i < 8; i++)
	{
		b = !b;
		for (int j = 0; j < 8; j++)
		{
			if (b == rec[i][j]) r1++;
			b = !b;
		}
	}
	b = true;
	for (int i = 0; i < 8; i++)
	{
		b = !b;
		for (int j = 0; j < 8; j++)
		{
			if (b == rec[i][j]) r2++;
			b = !b;
		}
	}
	return min(r1, r2);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	char c;
	cin >> N >> M;
	vector<vector<bool>> chess(N, vector<bool>(M));
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
		{
			cin >> c;
			if (c == 'W') chess[i][j] = true;
			else chess[i][j] = false;
		}
	int ans = 100;
	for (int i = 0; i <= N - 8; i++)
		for (int j = 0; j <= M - 8; j++)
		{
			vector<vector<bool>> vv(8, vector<bool>(8));
			for (int h = i; h < 8 + i; h++)
				for (int w = j; w < 8 + j; w++)
					vv[h - i][w - j] = chess[h][w];
			ans = min(ans, reColor(vv));
		}
	cout << ans << '\n';
}
// https://www.acmicpc.net/problem/1018