#include <iostream>

using namespace std;

pair<int, int> pos[26];
bool b[5][5];
int N, ans = -1;

bool checkRow(int r)
{
	for (int i = 0; i < 5; i++)
		if (!b[r][i])
			return false;
	return true;
}
bool checkCol(int c)
{
	for (int i = 0; i < 5; i++)
		if (!b[i][c])
			return false;
	return true;
}
bool checkCross()
{
	for (int i = 0; i < 5; i++)
		if (!b[i][i])
			return false;
	return true;
}
bool checkAntiCross()
{
	for (int i = 0; i < 5; i++)
		if (!b[4 - i][i])
			return false;
	return true;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
		{
			cin >> N;
			pos[N] = { i, j };
		}
	for (int i = 0; i < 25; i++)
	{
		cin >> N;
		b[pos[N].first][pos[N].second] = true;
		int cnt = checkAntiCross() + checkCross();
		for (int r = 0; r < 5; r++) cnt += checkCol(r);
		for (int c = 0; c < 5; c++) cnt += checkRow(c);
		if (ans < 0 && cnt >= 3)
		{
			ans = i + 1;
		}
	}
	cout << ans << '\n';
}


// https://www.acmicpc.net/problem/2578