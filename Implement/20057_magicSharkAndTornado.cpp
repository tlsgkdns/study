//

#include <iostream>
#include <vector>
using namespace std;

int N, ans = 0;
int dy[4] = { 0, -1, 0, 1 };
int dx[4] = { 1, 0, -1, 0 };
bool isInside(int y, int x)
{
	return (y >= 0 && x >= 0 && y <= N - 1 && x <= N - 1);
}
void moveSand(vector<vector<int>>& sand, int y, int x, int d)
{
	pair<int, int> side;
	int remain = sand[y][x];
	vector<pair<pair<int, int>, int>> movePos;
	float one = (float)sand[y][x] / 100;
	if (d == 0 || d == 2)
	{
		movePos.push_back({ { y, x + 2 * dx[d] },(int)(one * 5) });
		remain -= movePos.back().second;
		movePos.push_back({ {y - 1, x + dx[d]}, (int)(one * 10) });
		remain -= movePos.back().second;
		movePos.push_back({ {y + 1, x + dx[d]}, (int)(one * 10) });
		remain -= movePos.back().second;
		movePos.push_back({ {y + 2, x}, (int)(one * 2) });
		remain -= movePos.back().second;
		movePos.push_back({ {y - 2, x}, (int)(one * 2) });
		remain -= movePos.back().second;
		movePos.push_back({ {y + 1, x}, (int)(one * 7) });
		remain -= movePos.back().second;
		movePos.push_back({ {y - 1, x}, (int)(one * 7) });
		remain -= movePos.back().second;
		movePos.push_back({ {y + 1, x - dx[d]}, (int)one });
		remain -= movePos.back().second;
		movePos.push_back({ {y - 1, x - dx[d]}, (int)one });
		remain -= movePos.back().second;
		movePos.push_back({ {y, x + dx[d]}, remain });
	}
	else
	{
		movePos.push_back({ {y + 2 * dy[d], x}, (int)(one * 5) });
		remain -= movePos.back().second;
		movePos.push_back({ {y + dy[d], x + 1}, (int)(one * 10) });
		remain -= movePos.back().second;
		movePos.push_back({ {y + dy[d], x - 1}, (int)(one * 10) });
		remain -= movePos.back().second;
		movePos.push_back({ {y, x + 2}, (int)(one * 2) });
		remain -= movePos.back().second;
		movePos.push_back({ {y, x - 2}, (int)(one * 2) });
		remain -= movePos.back().second;
		movePos.push_back({ {y, x + 1}, (int)(one * 7) });
		remain -= movePos.back().second;
		movePos.push_back({ {y, x - 1}, (int)(one * 7) });
		remain -= movePos.back().second;
		movePos.push_back({ {y - dy[d], x - 1}, (int)one });
		remain -= movePos.back().second;
		movePos.push_back({ {y - dy[d], x + 1}, (int)one });
		remain -= movePos.back().second;
		movePos.push_back({ {y + dy[d], x}, remain });
	}
	for (auto info : movePos)
	{
		if (isInside(info.first.first, info.first.second))
			sand[info.first.first][info.first.second] += info.second;
		else
			ans += info.second;
	}
	sand[y][x] = 0;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	vector<vector<int>> A(N, vector<int>(N));
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> A[i][j];
	int ty = (N / 2), tx = (N / 2), d = 2, r = 1, cnt = 0;
	while (ty != 0 || tx != 0)
	{
		for (int i = 0; i < r; i++)
		{
			ty += dy[d];
			tx += dx[d];
			moveSand(A, ty, tx, d);
			if (ty == 0 && tx == 0) break;
		}
		if (d == 3) d = 0;
		else d++;
		if (cnt == 1)
		{
			cnt = 0;
			r++;
		}
		else
			cnt++;
	}
	cout << ans << '\n';
}
// https://www.acmicpc.net/problem/20057