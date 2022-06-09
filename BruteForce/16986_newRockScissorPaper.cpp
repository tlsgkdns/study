#include <iostream>

using namespace std;

int N, K;
int balance[10][10];
int oppHand[2][20];
int ans = 0;
void solve(int aWin, int bWin, int iWin, int hand, int opp, int aIdx, int bIdx)
{
	if (ans == 1 || aWin == K || bWin == K) return;
	if (iWin == K)
	{
		ans = 1;
		return;
	}
	if (opp == -1)
	{
		if (balance[oppHand[0][aIdx]][oppHand[1][bIdx]] == 2)
			solve(aWin + 1, bWin, iWin, hand, 0, aIdx + 1, bIdx + 1);
		else
			solve(aWin, bWin + 1, iWin, hand, 1, aIdx + 1, bIdx + 1);
	}
	else
	{
		for (int h = 1; h <= N; h++)
		{
			if (hand & (1 << h)) continue;
			int tmp = hand | (1 << h), idx = ((opp == 1) ? bIdx : aIdx);
			if (balance[h][oppHand[opp][idx]] == 2)
			{
				if (opp == 0)
					solve(aWin, bWin, iWin + 1, tmp, 1, aIdx + 1, bIdx);
				else
					solve(aWin, bWin, iWin + 1, tmp, 0, aIdx, bIdx + 1);
			}
			else
			{
				if (opp == 0)
					solve(aWin + 1, bWin, iWin, tmp, -1, aIdx + 1, bIdx);
				else
					solve(aWin, bWin + 1, iWin, tmp, -1, aIdx, bIdx + 1);
			}
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> K;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			cin >> balance[i][j];
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 20; j++)
			cin >> oppHand[i][j];
	solve(0, 0, 0, 0, 0, 0, 0);
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/16986