#include <iostream>
#include <algorithm>
using namespace std;

int opp[6] = { 5, 3, 4, 1, 2, 0 };
int dice[100001][6], N;
int getMax(int down, int idx)
{
	int s = 0;
	for (int i = 0; i < 6; i++)
	{
		if (i == down || opp[i] == down) continue;
		s = max(s, dice[idx][i]);
	}
	return s;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < 6; j++)
			cin >> dice[i][j];
	int ans = 0;
	for (int d = 0; d < 6; d++)
	{
		int btn = d, s = 0;
		for (int i = 0; i < N; i++)
		{
			s += getMax(btn, i);
			if (i == N - 1) continue;
			for (int j = 0; j < 6; j++)
				if (dice[i + 1][j] == dice[i][btn])
				{
					btn = opp[j];
					break;
				}
		}
		ans = max(ans, s);
	}
	cout << ans << '\n';
}


// https://www.acmicpc.net/problem/2116