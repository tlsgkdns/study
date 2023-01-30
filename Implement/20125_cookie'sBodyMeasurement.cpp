#include <iostream>

using namespace std;
using pii = pair<int, int>;
char B[1001][1001];
int N, LA = 0, RA = 0, W = 0, LL = 0, RL = 0;
pii H = { -1, -1 };
bool inRange(pii p)
{
	return p.first >= 0 && p.second >= 0 && p.first < N&& p.second < N;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{
			cin >> B[i][j];
			if (B[i][j] == '*' && H.first < 0) H = { i + 1, j };
		}
	pii tmp = H, tmp2;
	while (inRange(tmp) && B[tmp.first][tmp.second] == '*')
	{
		++LA;
		tmp = { tmp.first, tmp.second - 1 };
	}
	--LA;
	tmp = H;
	while (inRange(tmp) && B[tmp.first][tmp.second] == '*')
	{
		++RA;
		tmp = { tmp.first, tmp.second + 1 };
	}
	--RA;
	tmp = H;
	while (inRange(tmp) && B[tmp.first][tmp.second] == '*')
	{
		++W;
		tmp = { tmp.first + 1, tmp.second };
	}
	--W;
	tmp2 = { tmp.first, tmp.second + 1 };
	tmp = { tmp.first, tmp.second - 1 };
	while (inRange(tmp) && B[tmp.first][tmp.second] == '*')
	{
		++LL;
		tmp = { tmp.first + 1, tmp.second };
	}
	while (inRange(tmp2) && B[tmp2.first][tmp2.second] == '*')
	{
		++RL;
		tmp2 = { tmp2.first + 1, tmp2.second };
	}
	cout << H.first + 1 << " " << H.second + 1 << '\n';
	cout << LA << " " << RA << " " << W << " " << LL << " " << RL << '\n';
}

// https://www.acmicpc.net/problem/20125